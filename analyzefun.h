#ifndef ANALYZEFUN_H
#define ANALYZEFUN_H

#include <QWidget>
#include "stdafx.h"
#include <QPaintEvent>
#include <QMouseEvent>

namespace Ui {
class AnalyzeFun;
}

class AnalyzeFun : public QWidget
{
    Q_OBJECT

public:
    explicit AnalyzeFun(QWidget *parent = 0);
    ~AnalyzeFun();

    void   GetDbmDataNumber(int nMapDbm);
    double GetHzMaxDiffValueMin();
    double GetDbmMaxDiffValueMin();
    void   GetDataNumber();
    double GetMaxHzDataNumber();
    double GetMinHzDataNumber();
    double GetMaxDbmDataNumber();
    double GetMinDbmDataNumber();
    QPoint GetPointForWnd(QPoint pD);

    void GetNumberInVector();
    void GetNumberInVectorLast(std::vector<int> &vet);

    int round_double(double number);

    void GetAverValue();
    void GetBiggerAverValue();
    void GetDiffValueEqual();
    void GrawLineColor(QPainter *painter);

    void GetDrawCoord(QPainter *painter, int nAverX, int nAverY);
    void GetDrawPointXYCoord(QPainter *painter, QPoint pZero, int nAverX, int nAverY);

    void GetXYCoord(QPainter *painter);
    void GetDrawWaveCoord(QPainter *painter);
    void GetDrawGrapLine(QPainter *painter);

    void paintEvent(QPaintEvent *);

    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
//    bool eventFilter(QObject *,QEvent *);    //注意这里

    void AllBtnAction(bool bCanPress);

    void find_llap(std::vector<int> &vet, int n);

    void find_llap_zero(std::vector<int> &vet, int n);

    bool find_delat_in_vec(std::vector<int> &vec);

private slots:
    void on_DataInputBtn_clicked();

    void on_PictureBtn_clicked();

    void on_ArgsBtn_clicked();

    void on_AnalyzeBtn_clicked();

    void on_MarkBtn_clicked();

    void on_DataCatBtn_clicked();

    void on_PartAnalyzeBtn_clicked();

    void on_GraphBtn_clicked();

    void on_PackageBtn_clicked();

    void on_StartBtn_clicked();

    void on_combkBtn_clicked();

private:
    Ui::AnalyzeFun *ui;

    std::map<std::string,std::string> m_mapDataType;
    std::map<std::string,std::string> m_mapNewDataType;
    std::vector<std::string>          m_vecType;
    std::vector<std::string>          m_vecFindType;

    std::map<int,std::map<int,int>>   m_dp;

    std::map<int,std::map<int,int>>   m_mapDp;
    std::vector<int>                  m_vecDiff;
    std::vector<int>                  m_vecSize;

    std::vector<int>                  m_vecFirst;
    std::vector<int>                  m_vecSecond;
    std::vector<int>                  m_vecThree;

    std::vector<int>                  vet_dc;

    std::vector<int>                  m_vecMapType;
    std::map<int,int>                 m_mapVecType;

    std::vector<QPoint>               m_vecPoint;

    bool mbCanSet;
    int MAX_LEN;
    int MIN_LEN;

    int m_nArray[1000];


    double m_dMaxHzNumber;
    double m_dMinHzNumber;
    double m_dMaxDbmNumber;
    double m_dMinDbmNumber;

    double m_dDbmAverValue;

    QPoint m_pLabTop;
    QPoint m_pZero;
    QPoint m_pos;
    int m_nLenX;
    double m_nLenY;
    int m_nMinX;
    int m_nMinY;
    int m_nLabLenX;
    int m_nLabLenY;
    int m_nHzDiffValue;
    double m_nDbmDiffValue;

    int m_nDifV[3];

    bool m_bDataInputFlag;
    bool m_bCanPress;
    bool m_bPrint;
    bool m_bCanInster;
    bool m_bCanDraw;
    bool m_bSetNum;

};

#endif // ANALYZEFUN_H
