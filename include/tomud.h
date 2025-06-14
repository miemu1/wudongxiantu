#define TMI(x) ("\x19"+x+"\x1A")
#define TMA "\x19"
#define TMB "\x1A"
#define INFO TMI
#define HEND sprintf("%c",18)

#define ALERT(x) TMI("alert "+x)
#define PTEXT(x) TMI("ptext "+x)
#define MTEXT(x) TMI("ptext "+x)
#define L_ITEM(x) RANK_D->new_short(x)
#define L_ICON(x) TMI("licon "+x)
#define L_ICONS(x) TMI("licon "+RANK_D->new_short(x))
#define CLEAN0  TMI("lbclear0")
#define ADD0(x) TMI("lbadd0 "+L_ITEM(x)+";")
#define REM0(x) TMI("lbrem0 "+L_ITEM(x)+";")
#define CLEAN1  TMI("lbclear1")
#define ADD1(x) TMI("lbadd1 "+L_ITEM(x)+";")
#define REM1(x) TMI("lbrem1 "+L_ITEM(x)+";")
#define CLEAN2  TMI("lbclear2")
#define ADD2(x) TMI("lbadd2 "+L_ITEM(x)+";")
#define REM2(x) TMI("lbrem2 "+L_ITEM(x)+";")


//武功绝招威力系数
#define GAOJI		13//高级武功系数
#define DIJI		10//低级武功系数
#define DPXS		0.85//控制绝招的命中率，经典算法同级命中率变为65%
//#define DIJI		6
#define BUSYMAX		30//绝招繁忙最大时间
#define BUSYMIN		3//绝招繁忙最短时间
#define LIANMAX		10//连招最大次数
