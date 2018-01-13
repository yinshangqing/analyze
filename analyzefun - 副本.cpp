#include "analyzefun.h"
#include "ui_analyzefun.h"

struct result
{
    int max_len;
    int i;
    int j;
};

struct Max_Size
{
    int max_len;
    int i;
};

Max_Size first_size,second_size,three_size;

int max(int a, int b)
{
    return a > b ? a : b;
}

void bubble_sort(std::vector<int> &a)
{
    int i, j, temp;
    for (j = 0; j < a.size() - 1; j++)
    {
        for (i = 0; i < a.size() - 1 - j; i++)
        {
            if(a.at(i) > a.at(i + 1))
            {
                temp = a.at(i);
                a.at(i) = a.at(i + 1);
                a.at(i + 1) = temp;
            }
        }
    }
}

AnalyzeFun::AnalyzeFun(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnalyzeFun)
{
    ui->setupUi(this);
    this->resize(800,500);
    this->setFixedSize(800,500);
    this->setWindowTitle(WND_TITLE_STR);
    m_dMaxHzNumber  = 0.0;
    m_dMinHzNumber  = 0.0;
    m_dMaxDbmNumber = 0.0;
    m_dMinDbmNumber = 0.0;
    m_nHzDiffValue  = 0;
    m_nDbmDiffValue = 0;

    m_pos = m_pZero = QPoint(230,310);
    m_nLenX = 550;
    m_nLenY = 280;
    m_nMinX = m_nLenX / CONST_AVER_FLAG;
    m_nMinY = m_nLenY / CONST_AVER_FLAG;

    mbCanSet = m_bCanDraw = m_bCanInster = m_bPrint = m_bCanPress = m_bDataInputFlag = false;

    memset(m_nDifV,0,sizeof(m_nDifV));

}

AnalyzeFun::~AnalyzeFun()
{
    delete ui;
}

void AnalyzeFun::GetDbmDataNumber(int nMapDbm)
{
    std::map<std::string,std::string>::iterator itemData = m_mapDataType.find(m_vecType.at(nMapDbm));
    if(atof(itemData->second.data()) >= m_dMaxDbmNumber)
    {
        m_dMaxDbmNumber = atof(itemData->second.data());
    }
    if(atof(itemData->second.data()) < m_dMinDbmNumber)
    {
        m_dMinDbmNumber = atof(itemData->second.data());
    }
}

double AnalyzeFun::GetHzMaxDiffValueMin()
{
    return GetMaxHzDataNumber() - GetMinHzDataNumber();
}

double AnalyzeFun::GetDbmMaxDiffValueMin()
{
    return GetMaxDbmDataNumber() - GetMinDbmDataNumber();
}

void AnalyzeFun::GetDataNumber()
{
    if(m_vecType.size() == 0 || m_mapDataType.size() == 0)
    {
        return;
    }
    m_dMaxHzNumber = atof(m_vecType.at(0).data());
    m_dMinHzNumber = atof(m_vecType.at(0).data());
    std::map<std::string,std::string>::iterator itemData = m_mapDataType.find(m_vecType.at(0));
    m_dMaxDbmNumber = atof(itemData->second.data());
    m_dMinDbmNumber = atof(itemData->second.data());
    for(int i = 1;i < m_vecType.size();++ i)
    {
        if(m_dMaxHzNumber <= atof(m_vecType.at(i).data()))
        {
            m_dMaxHzNumber = atof(m_vecType.at(i).data());
        }
        if(m_dMinHzNumber > atof(m_vecType.at(i).data()))
        {
            m_dMinHzNumber = atof(m_vecType.at(i).data());
        }
        GetDbmDataNumber(i);
    }
}

double AnalyzeFun::GetMaxHzDataNumber()
{
    return m_dMaxHzNumber;
}

double AnalyzeFun::GetMinHzDataNumber()
{
    return m_dMinHzNumber;
}

double AnalyzeFun::GetMaxDbmDataNumber()
{
    return m_dMaxDbmNumber;
}

double AnalyzeFun::GetMinDbmDataNumber()
{
    return m_dMinDbmNumber;
}

// 将屏幕的点转化为坐标点
QPoint AnalyzeFun::GetPointForWnd(QPoint pD)
{
    if(m_dMinHzNumber < 10000)
    {
        return m_pos;
    }
    unsigned long lAverX =  m_nHzDiffValue / m_nLenX;
    double lAverY = m_nLenY / m_nDbmDiffValue;
    QPoint pNewSor = QPoint(m_dMinHzNumber + (pD.x() - 230) * lAverX ,m_dMinDbmNumber + (310 - pD.y()) / lAverY);
    return pNewSor;
}

int AnalyzeFun::round_double(double number)
{
//    return (number > 0.0) ? (number + 0.5) : (number - 0.5);
    return number + 0.2;
}

void AnalyzeFun::GetAverValue()
{
    double dSum = 0.0;
    std::map<std::string,std::string>::iterator iter;
    for(iter = m_mapDataType.begin();iter != m_mapDataType.end();++ iter)
    {
        dSum += atof(iter->second.data());
    }
    m_dDbmAverValue = dSum / m_mapDataType.size();
    qDebug() << "m_dDbmAverValue: " << m_dDbmAverValue;
}

// 得到比平均值大的数
void AnalyzeFun::GetBiggerAverValue()
{
    qDebug() << "准备删除...";
    std::map<std::string,std::string>::iterator Iter = m_mapNewDataType.begin();
    while(Iter != m_mapNewDataType.end())
    {
        qDebug() << atof(Iter->second.data());
        if(atof(Iter->second.data()) > m_dDbmAverValue)
        {
            ++ Iter;
            continue;
        }
        qDebug() << "删除...";
        m_mapNewDataType.erase(Iter ++);
    }
    qDebug() << "删除成功...";
    qDebug() << m_mapNewDataType.size();
}
// 得到等差数列
void AnalyzeFun::GetDiffValueEqual()
{
    m_mapVecType.clear();
    m_vecMapType.clear();
    std::map<std::string,std::string>::iterator iter = m_mapNewDataType.begin();
    for(;iter != m_mapNewDataType.end();++ iter)
    {
        if(mbCanSet)
        {
            if(round_double(atof(iter->first.data()))/1000000 > MAX_LEN || round_double(atof(iter->first.data()))/1000000 < MIN_LEN)
                continue;
        }
        m_vecMapType.push_back(round_double(atof(iter->first.data()))/1000000);
        m_mapVecType.insert(std::map<int,int>::value_type(round_double(atof(iter->first.data())/1000000),round_double(atof(iter->second.data()))));

    }
//    find_llap(m_vecMapType,m_vecMapType.size());
    find_llap_zero(m_vecMapType,m_vecMapType.size());

}

void AnalyzeFun::GrawLineColor(QPainter *painter)
{
    if(m_vecFirst.size() == 0)
    {
        return;
    }
    qDebug() << m_mapVecType[m_vecFirst.at(0)];
    painter->setPen(Qt::red);
    // x1 = aver1/aver0*(x - x0)
    QPoint pOldPoint = QPoint(((m_vecFirst.at(0)*1000000 - m_dMinHzNumber) * m_nLenX / m_nHzDiffValue + 230),(310 - (m_mapVecType[m_vecFirst.at(0)] - m_dMinDbmNumber) * m_nLenY / m_nDbmDiffValue));
    for(int i = 1;i < m_vecFirst.size();++ i)
    {
        QPoint pNewPoint = QPoint(((m_vecFirst.at(i)*1000000 - m_dMinHzNumber) * m_nLenX / m_nHzDiffValue + 230),(310 - (m_mapVecType[m_vecFirst.at(i)] - m_dMinDbmNumber) * m_nLenY / m_nDbmDiffValue));
        qDebug() << "x: " << pNewPoint.x() << "y: " << pNewPoint.y();
        painter->drawLine(pOldPoint,pNewPoint);
        pOldPoint = pNewPoint;
    }
    if(m_vecSecond.size() == 0)
    {
        return;
    }
    painter->setPen(Qt::green);
    // x1 = aver1/aver0*(x - x0)
    pOldPoint = QPoint(((m_vecSecond.at(0)*1000000 - m_dMinHzNumber) * m_nLenX / m_nHzDiffValue + 230),(310 - (m_mapVecType[m_vecSecond.at(0)] - m_dMinDbmNumber) * m_nLenY / m_nDbmDiffValue));
    for(int i = 1;i < m_vecSecond.size();++ i)
    {
        QPoint pNewPoint = QPoint(((m_vecSecond.at(i)*1000000 - m_dMinHzNumber) * m_nLenX / m_nHzDiffValue + 230),(310 - (m_mapVecType[m_vecSecond.at(i)] - m_dMinDbmNumber) * m_nLenY / m_nDbmDiffValue));
        painter->drawLine(pOldPoint,pNewPoint);
        qDebug() << "x: " << pNewPoint.x() << "y: " << pNewPoint.y();
        pOldPoint = pNewPoint;
    }
    if(m_vecThree.size() == 0)
    {
        return;
    }
    painter->setPen(Qt::yellow);
    // x1 = aver1/aver0*(x - x0)
    pOldPoint = QPoint(((m_vecThree.at(0)*1000000 - m_dMinHzNumber) * m_nLenX / m_nHzDiffValue + 230),(310 - (m_mapVecType[m_vecThree.at(0)] - m_dMinDbmNumber) * m_nLenY / m_nDbmDiffValue));
    for(int i = 1;i < m_vecThree.size();++ i)
    {
        QPoint pNewPoint = QPoint(((m_vecThree.at(i)*1000000 - m_dMinHzNumber) * m_nLenX / m_nHzDiffValue + 230),(310 - (m_mapVecType[m_vecThree.at(i)] - m_dMinDbmNumber) * m_nLenY / m_nDbmDiffValue));
        painter->drawLine(pOldPoint,pNewPoint);
        pOldPoint = pNewPoint;
    }
}

// 绘制坐标系
void AnalyzeFun::GetDrawCoord(QPainter *painter,int nAverX,int nAverY)
{
    QPoint pZero = QPoint(m_pLabTop.x(),m_pLabTop.y() + m_nLabLenY);
    GetDrawPointXYCoord(painter,pZero,nAverX,nAverY);
}

void AnalyzeFun::GetDrawPointXYCoord(QPainter *painter,QPoint pZero, int nAverX, int nAverY)
{
    painter->drawLine(pZero,QPoint(pZero.x() - nAverX,nAverY));
    painter->drawLine(pZero,QPoint(pZero.x(),pZero.y() - nAverY));
}
// 绘制函数
void AnalyzeFun::GetXYCoord(QPainter *painter)
{
    m_nHzDiffValue  = (int)GetHzMaxDiffValueMin();
    m_nDbmDiffValue = GetDbmMaxDiffValueMin();

    int i;
    char strX[20];
    char strY[20];
    for(i = 1;i < CONST_AVER_FLAG;++ i)
    {
        double dXValue = (m_dMinHzNumber  + m_nHzDiffValue  / CONST_AVER_FLAG * i) / CONST_HZ_MILLION;
        double dYValue = (m_dMinDbmNumber + m_nDbmDiffValue / CONST_AVER_FLAG * i);
        sprintf(strX,"%d",round_double(dXValue));
        sprintf(strY,"%d",round_double(dYValue));

        // 绘制坐标点对应的坐标值
        painter->drawText(QPoint(m_pZero.x() + m_nMinX * i - 2,m_pZero.y() + 10),strX);
        painter->drawText(QPoint(m_pZero.x() - 18,m_pZero.y() - m_nMinY*i + 5),strY);
    }
    sprintf(strX,"%s","M");
    sprintf(strY,"%s","dbm");
    painter->drawText(QPoint(m_pZero.x() + m_nMinX * i - 2,m_pZero.y() + 10),strX);
    painter->drawText(QPoint(m_pZero.x() - 18,m_pZero.y() - m_nMinY*i + 5),strY);

}

void AnalyzeFun::GetDrawWaveCoord(QPainter *painter)
{
    if(m_vecType.size() == 0 || m_mapDataType.size() == 0)
    {
        return;
    }
    painter->setPen(Qt::blue);
    // x1 = aver1/aver0*(x - x0)
    QPointF pOldPoint = QPointF(((atof(m_vecType.at(0).data()) - m_dMinHzNumber) * m_nLenX / m_nHzDiffValue + 230),(310 - (atof(m_mapDataType.find(m_vecType.at(0))->second.data()) - m_dMinDbmNumber) * m_nLenY / m_nDbmDiffValue));
    for(int i = 1;i < m_vecType.size();++ i)
    {
        QPointF pNewPoint = QPointF(((atof(m_vecType.at(i).data()) - m_dMinHzNumber) * m_nLenX / m_nHzDiffValue + 230),(310 - (atof(m_mapDataType.find(m_vecType.at(i))->second.data()) - m_dMinDbmNumber) * m_nLenY / m_nDbmDiffValue));
        painter->drawLine(pOldPoint,pNewPoint);
        pOldPoint = pNewPoint;
    }
}

void AnalyzeFun::GetDrawGrapLine(QPainter *painter)
{
    if(!m_bCanDraw)
    {
        return;
    }
    if(m_vecPoint.size() < 1)
    {
        return;
    }
    painter->setPen(Qt::red);
    QPoint pOldPoint = m_vecPoint.at(0);
    for(int i = 1;i < m_vecPoint.size();++ i)
    {
        QPoint pNewPoint = m_vecPoint.at(i);
        painter->drawLine(pOldPoint,pNewPoint);
        pOldPoint = pNewPoint;
    }

}

// 数据导入
void AnalyzeFun::on_DataInputBtn_clicked()
{
    m_dMaxHzNumber  = 0.0;
    m_dMinHzNumber  = 0.0;
    m_dMaxDbmNumber = 0.0;
    m_dMinDbmNumber = 0.0;
    m_nHzDiffValue  = 0;
    m_nDbmDiffValue  = 0;
    memset(m_nDifV,0,sizeof(m_nDifV));
    QFileDialog* fd = new QFileDialog(this);//创建打开文件对话框
    QString fileName = fd->getOpenFileName(this,tr("Open File"),"./TESTDATA",tr("Excel(*.csv)"));
    if(fileName == "")
          return;
    QDir dir = QDir::current();
    QFile file(dir.filePath(fileName));
    if(!file.open(QIODevice::ReadOnly))
    {
         qDebug()<<"OPEN FILE FAILED";
         file.close();
         return;
    }

    QTextStream * out = new QTextStream(&file);//文本流
    QStringList tempOption = out->readAll().split("\r\n");//每行以\n区分
    m_mapDataType.clear();
    m_vecType.clear();
    m_mapNewDataType.clear();
    m_vecFindType.clear();
    m_vecMapType.clear();
    m_vecFirst.clear();
    m_vecSecond.clear();
    m_vecThree.clear();
    ui->textEdit->clear();
    AllBtnAction(false);
    for(int i = 0 ; i < tempOption.count() - 1; i++)
    {
        QString tempbar = tempOption.at(i).left(tempbar.length() - 1);//一行中的单元格以，区分
        // 将读取到的数据放入到textEdit中
        ui->textEdit->append(tempbar.left(tempbar.length()));
        qDebug() << tempbar;
        int index = tempbar.indexOf(",");
        QString strDob1 = tempbar.left(index);
        std::string strDobFirst = strDob1.toStdString();
        QString strDob2 = tempbar.remove(0,index).remove(0,1);
        strDob2 = strDob2.left(strDob2.length() - 1);
        std::string strDobSecond = strDob2.toStdString();
        m_vecType.push_back(strDobFirst);
        m_mapDataType.insert(std::map<std::string,std::string>::value_type(strDobFirst,strDobSecond));
    }
    m_mapNewDataType.insert(m_mapDataType.begin(),m_mapDataType.end());
    file.close();//操作完成后记得关闭文件
    fd->close();
    AllBtnAction(true);
}

// 图形绘制
void AnalyzeFun::on_PictureBtn_clicked()
{
    GetDataNumber();
    m_nHzDiffValue  = (int)GetHzMaxDiffValueMin();
    m_nDbmDiffValue = (int)GetDbmMaxDiffValueMin();
    update();
}
// 参数设定
void AnalyzeFun::on_ArgsBtn_clicked()
{
    ui->textEdit->clear();
}
// 基频分析
void AnalyzeFun::on_AnalyzeBtn_clicked()
{
    ui->textEdit->append("基频分析");
    QString strAnaly;
    if(m_nDifV[2] != 0)
    {
        strAnaly.sprintf("\t%dM\t%dM\t%dM",m_nDifV[0],m_nDifV[1],m_nDifV[2]);
    }
    else if(m_nDifV[1] != 0)
    {
        strAnaly.sprintf("\t%dM\t%dM",m_nDifV[0],m_nDifV[1]);
    }
    else if(m_nDifV[0] != 0)
    {
        strAnaly.sprintf("\t%dM",m_nDifV[0]);
    }
    else
    {
        QString str("\t公差寻找失败，请重新操作");
        strAnaly = str;
    }
    ui->textEdit->append(strAnaly);
}
// 谐波标记
void AnalyzeFun::on_MarkBtn_clicked()
{
    if(m_vecFirst.size() != 0)
        return;
    // 关闭设定曲线
    m_bCanDraw = false;
    // 得到平均值
    GetAverValue();
    // 先得到比平均值大的数
    GetBiggerAverValue();
    GetDiffValueEqual();
    update();

    QString str("查看等差数列\t\t\t\t\t\t\t公差");
    ui->textEdit->append(str);
    if(m_vecFirst.size() == 0)
    {
        QString str1("\t未找到有效的等差数列，请重新操作");
        ui->textEdit->append(str1);
        return;
    }
    QString strFrst;
    memset(m_nDifV,0,sizeof(m_nDifV));
    m_nDifV[0] = m_vecFirst.at(1) - m_vecFirst.at(0);
    for(int i=0;i<m_vecFirst.size();++i)
    {
        strFrst.append(QString("%1\t").arg(m_vecFirst.at(i)));
    }
    strFrst.append(QString("\t\t%1").arg(m_nDifV[0]));
    ui->textEdit->append(strFrst);
    if(m_vecSecond.size() == 0)
        return;
    QString strScnd;
    m_nDifV[1] = m_vecSecond.at(1) - m_vecSecond.at(0);
    for(int i=0;i<m_vecSecond.size();++i)
    {
        strScnd.append(QString("%1\t").arg(m_vecSecond.at(i)));
    }
    strScnd.append(QString("\t\t%1").arg(m_nDifV[1]));
    ui->textEdit->append(strScnd);

    if(m_vecThree.size() == 0)
        return;
    qDebug() << "0" << m_vecThree.at(0) << "1" << m_vecThree.at(1) << "2" << m_vecThree.at(2);
    QString strTree;
    m_nDifV[2] = m_vecThree.at(1) - m_vecThree.at(0);
    for(int i=0;i<m_vecThree.size();++i)
    {
        strTree.append(QString("%1\t").arg(m_vecThree.at(i)));
    }
    strTree.append(QString("\t\t%1").arg(m_nDifV[2]));
    ui->textEdit->append(strTree);

}
// 数据查看
void AnalyzeFun::on_DataCatBtn_clicked()
{
    /* 开启鼠标追踪 */
    m_bPrint = !m_bPrint;
    if(m_bPrint)
    {
        QString str("开始查看坐标：");
        ui->textEdit->append(str);
        this->setMouseTracking(true);
    }
    else
    {
        QString str("关闭查看坐标");
        ui->textEdit->append(str);
        this->setMouseTracking(false);
    }
}
// 局部分析
void AnalyzeFun::on_PartAnalyzeBtn_clicked()
{
    if(m_vecPoint.size() == 0)
        return;

    MAX_LEN = MIN_LEN = m_vecPoint.at(0).x();
    for(int i=1;i<m_vecPoint.size();++i)
    {
        if(MIN_LEN > m_vecPoint.at(i).x())
        {
            MIN_LEN = m_vecPoint.at(i).x();
        }
        if(MAX_LEN < m_vecPoint.at(i).x())
        {
            MAX_LEN = m_vecPoint.at(i).x();
        }
    }
    m_bCanDraw = false;
    mbCanSet = true;

}
// 设定曲线
void AnalyzeFun::on_GraphBtn_clicked()
{
//    QString str("开始设定曲线");
//    ui->textEdit->append(str);
    QString str("\345\274\200\345\247\213\350\256\276\345\256\232\346\233\262\347\272\277");
    ui->textEdit->append(str);
    m_bCanDraw = m_bCanInster = true;

    m_vecPoint.clear();
}
// 打包功能
void AnalyzeFun::on_PackageBtn_clicked()
{

}
// 开始分析
void AnalyzeFun::on_StartBtn_clicked()
{
    m_bCanDraw = true;
    m_bCanInster = false;
    update();
    double number = ui->textEdit->toPlainText().toFloat();
    qDebug() << number;
    m_dDbmAverValue = number;
    QString str("设定成功");
    ui->textEdit->append(str);
    if(m_vecFirst.size() != 0)
        return;
    // 得到平均值
//    GetAverValue();
    // 先得到比平均值大的数
    GetBiggerAverValue();
    GetDiffValueEqual();
    update();

    QString str1("查看等差数列\t\t\t\t\t\t\t公差");
    ui->textEdit->append(str1);
    if(m_vecFirst.size() == 0)
    {
        QString str1("\t未找到有效的等差数列，请重新操作");
        ui->textEdit->append(str1);
        return;
    }
    QString strFrst;
    memset(m_nDifV,0,sizeof(m_nDifV));
    m_nDifV[0] = m_vecFirst.at(1) - m_vecFirst.at(0);
    for(int i=0;i<m_vecFirst.size();++i)
    {
        strFrst.append(QString("%1\t").arg(m_vecFirst.at(i)));
    }
    strFrst.append(QString("\t\t%1").arg(m_nDifV[0]));
    ui->textEdit->append(strFrst);
    if(m_vecSecond.size() == 0)
        return;
    QString strScnd;
    m_nDifV[1] = m_vecSecond.at(1) - m_vecSecond.at(0);
    for(int i=0;i<m_vecSecond.size();++i)
    {
        strScnd.append(QString("%1\t").arg(m_vecSecond.at(i)));
    }
    strScnd.append(QString("\t\t%1").arg(m_nDifV[1]));
    ui->textEdit->append(strScnd);

    if(m_vecThree.size() == 0)
        return;
    QString strTree;
    m_nDifV[2] = m_vecThree.at(1) - m_vecThree.at(0);
    for(int i=0;i<m_vecThree.size();++i)
    {
        strTree.append(QString("%1\t").arg(m_vecThree.at(i)));
    }
    strTree.append(QString("\t\t%1").arg(m_nDifV[2]));
    ui->textEdit->append(strTree);

}

// 绘制坐标和QT波形图
void AnalyzeFun::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawLine(m_pZero,QPoint(m_pZero.x(),m_pZero.y() - m_nLenY));
    painter.drawLine(QPoint(m_pZero.x(),m_pZero.y() - m_nLenY),QPoint(m_pZero.x() - 5,m_pZero.y() - m_nLenY + 5));
    painter.drawLine(QPoint(m_pZero.x(),m_pZero.y() - m_nLenY),QPoint(m_pZero.x() + 5,m_pZero.y() - m_nLenY + 5));
    painter.drawLine(m_pZero,QPoint(m_pZero.x() + m_nLenX,m_pZero.y()));
    painter.drawLine(QPoint(m_pZero.x() + m_nLenX,m_pZero.y()),QPoint(m_pZero.x() + m_nLenX - 5,m_pZero.y() - 5));
    painter.drawLine(QPoint(m_pZero.x() + m_nLenX,m_pZero.y()),QPoint(m_pZero.x() + m_nLenX - 5,m_pZero.y() + 5));
    for(int i = 1;i < CONST_AVER_FLAG;i ++)
    {
        painter.drawLine(QPoint(m_pZero.x() + m_nMinX*i,m_pZero.y()),QPoint(m_pZero.x() + m_nMinX*i,m_pZero.y() - 5));
        painter.drawLine(QPoint(m_pZero.x(),m_pZero.y() - m_nMinY*i),QPoint(m_pZero.x() + 5,m_pZero.y() - m_nMinY*i));
    }
    GetXYCoord(&painter);
    GetDrawWaveCoord(&painter);
    GrawLineColor(&painter);
    GetDrawGrapLine(&painter);
//    GetDrawCoord(&painter,m_nDbmDiffValue,m_nHzDiffValue);
}

void AnalyzeFun::mouseMoveEvent(QMouseEvent *e)
{

}

void AnalyzeFun::mousePressEvent(QMouseEvent *e)
{
    if(e->buttons() == Qt::LeftButton)
    {
        if(e->pos().x() > 230 && e->pos().x() < 780)
        {
            if(e->pos().y() > 30 && e->pos().y() < 310)
            {
                this->setMouseTracking(false);
                m_pos = e->pos();
                if(m_bCanDraw){
                    m_vecPoint.push_back(m_pos);
                }
                update();
                qDebug() << "x: " << e->pos().x() << "y: " << e->pos().y();
                m_bCanPress = true;
                QPoint pot = GetPointForWnd(e->pos());
                if(m_bCanDraw || m_bPrint)
                {
                    QString strPot;
                    strPot.sprintf("\tx = %d\t\ty = %d",pot.x(),pot.y());
                    ui->textEdit->append(strPot);
                    this->setMouseTracking(true);
                }
            }
        }
    }
}

void AnalyzeFun::AllBtnAction(bool bCanPress)
{
    ui->AnalyzeBtn->setEnabled(bCanPress);
    ui->ArgsBtn->setEnabled(bCanPress);
    ui->DataCatBtn->setEnabled(bCanPress);
    ui->DataInputBtn->setEnabled(bCanPress);
    ui->MarkBtn->setEnabled(bCanPress);
    ui->StartBtn->setEnabled(bCanPress);
    ui->PartAnalyzeBtn->setEnabled(bCanPress);
    ui->GraphBtn->setEnabled(bCanPress);
    ui->PackageBtn->setEnabled(bCanPress);
    ui->PictureBtn->setEnabled(bCanPress);

}

void AnalyzeFun::find_llap(std::vector<int> &vet, int n)
{
    vet_dc.clear();
    std::map<int,std::map<int,int>> dp;
    int i,j,k;
    struct result result;
    for(i = 0; i < n; i++)
    {
        dp[i][n] = 2; //因为以arry[n]为第二个元素的等差数列长度一定为2
    }
    if(n < 2)
    {
        for(i = 0; i < 2;++ i)
            printf("%d ",vet.at(i));
        return;
    }
    result.max_len = 0;
    for(j = n-1; j >= 1; j--)
    {
        i = j-1;k = j+1;
        while(i >= 0 && k < n)
        {
            if(vet.at(i) + vet.at(k) > vet.at(j)<<1) //如果和ai+ak>2aj,说明ak-aj>aj-ai,这个构造不成等差数列,则k以后的更不行，因为数组是升序
            {
                dp[i][j] = 2;                //所以此步骤直接赋值为2，及只有ai aj构造成等差数列
                i--;
            }
            else if(vet.at(i) + vet.at(k) < vet.at(j)<<1)
            {
                k++;       //如果ai+ak<2aj,说明ak-aj<aj-ai,所以以ai aj开头的等差数列，往后遍历，可能还有新的元素符合公差，所以k++
            }
            else
            {
                /*如果ai+ak=2aj,则正好构成等差数列，直接将前一个子问题的解+1即可*/	
                dp[i][j] = dp[j][k]+1;
                result.max_len = max(result.max_len,dp[i][j]);
                if(result.max_len == dp[i][j])
                {
                    result.i = i;
                    result.j = j;
                }
                i--;k++;
            }
        }
        if(result.max_len == 0)
        {
            result.max_len = 2;
            result.i = 0;
            result.j = 1;
        }
        while(i >= 0) /*这个循环是因为k已经到最后了，所以以这个j为第二个元素的所有数列都是2*/
        {
            dp[i][j] = 2;
            i--;
        }
    }
    int delta = vet.at(result.j) - vet.at(result.i);
    int rm = result.i;
	int last  = vet.at(result.i)+(result.max_len-1)*delta;
    for(i = vet.at(result.i); i <= last; i+=delta)
    {
        vet_dc.push_back(i);
		qDebug() << i;
    }
}

void AnalyzeFun::find_llap_zero(std::vector<int> &vet, int n)
{
    bubble_sort(vet);
    for(int b = 0;b < vet.size();++ b)
    {
        qDebug() << vet.at(b);
    }
    vet_dc.clear();
    int delta;

    if(n < 3)
        return;
    for(int a = 0;a < n;++ a)
    {
        m_vecDiff.push_back(0);
        m_vecSize.push_back(0);
    }
    for(int i = 0;i < n - 1;++ i)
    {
//        m_vecDiff.at(i) = delta = vet.at(i);
        m_vecDiff.at(i) = vet.at(i);
        for(int j = i + 1;j < n;++ j)
        {
            delta = vet.at(i+1) - vet.at(i);
			if(delta == 0)
				continue;
            if(vet.at(j) % delta == 0)
            {
                m_vecDiff.at(i) = m_vecDiff.at(i) + delta;
                if(m_vecDiff.at(i) == vet.at(j))
                {
                    ++ m_vecSize.at(i);
                }
                else if(m_vecDiff.at(i) > vet.at(j))
                {
                    break;
                }
                qDebug() << m_vecDiff.at(i) + delta;
            }else{
                continue;
            }

        }
    }
    first_size.max_len = 0;
    first_size.i  = 0;
    second_size.max_len = 0;
    second_size.i  = 0;
    three_size.max_len = 0;
    three_size.i  = 0;
    for(int p = 1;p < m_vecSize.size();++ p)
    {
        if(first_size.max_len < m_vecSize.at(p))
        {
            three_size.max_len = second_size.max_len;
            three_size.i = second_size.i;
            second_size.max_len = first_size.max_len;
            second_size.i = first_size.i;
            first_size.max_len = m_vecSize.at(p);
            first_size.i  = p;
        }
    }
    // 将得到的方人到容器中去
    m_vecFirst.clear();
    m_vecSecond.clear();
    m_vecThree.clear();
    if(first_size.max_len > 2)
    {
        for(int w = 0;w < first_size.max_len;++ w)
        {
            m_vecFirst.push_back(vet.at(first_size.i)*(w + 1));
        }
    }
    if(second_size.max_len > 2)
    {
        for(int s = 0;s < second_size.max_len;++ s)
        {
            m_vecSecond.push_back(vet.at(second_size.i)*(s + 1));
        }
    }
    if(three_size.max_len > 2)
    {
        for(int z = 0;z < three_size.max_len;++ z)
        {
            m_vecThree.push_back(vet.at(three_size.i)*(z + 1));
        }
    }

}







