#ifndef STDAFX
#define STDAFX

/* 头文件的及变量声明存放 */
/** X 为Dmb坐标，Y 为Hz坐标 **/
#include <QDebug>
#include <QWidget>
#include <QPalette>
#include <QPixmap>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <map>
#include <vector>
#include <QDateTime>
#include "analyzefun.h"
//#include "sort.h"

//typedef struct {
//    bool run;
//    bool draw;
//}COMMAND;

//COMMAND com;

//extern std::map<std::string,std::string> m_mapDataType;
//extern std::map<std::string,std::string> m_mapNewDataType;
//extern std::vector<std::string>          m_vecType;
//extern std::vector<std::string>          m_vecFindType;
//extern std::vector<std::string>          m_vecFirst;
//extern std::vector<std::string>          m_vecSecond;
//extern std::vector<std::string>          m_vecThree;

#define CONST_HZ_THOUSAND      1000
#define CONST_HZ_MILLION       1000000

#define CONST_AVER_FLAG        7

#define CONST_EQUAL_MAX        3

#define CONST_LEN_MAX          20

#define INPUT_EDIT_MSG         "请您输入%s进行分析"

#define WND_TITLE_STR          "\344\276\277\346\220\272\345\274\217\347\224\265\347\243\201\345\271\262\346\211\260\345\210\206\346\236\220\350\243\205\347\275\256"

#endif // STDAFX

