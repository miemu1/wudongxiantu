#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
string status_color(int current, int max);
int potential_lv(int exp);

int main(object me, string arg,object who)
{
object ob;
int craze;
mapping my;
string str,skill_type,level,ceshii,vip;
string lv4;
object weapon;
int attack_points, dodge_points, parry_points;
int zjs,hjs,hzlh,bbfj,hgbf,blxs,lxjt,zhtx,yjck,gongji,dj,djj;
mixed need;
seteuid(getuid());
if(!arg) ob = me;
else if (wizardp(me))
{
 ob = present(arg, environment(me));
 if (!ob) ob = find_player(arg);
 if (!ob) ob = find_living(arg);
 if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
}
else return notify_fail("ֻ����ʦ�ſ��Բ쿴���˵�״̬��\n");

my = ob->query_entire_dbase();
if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
return notify_fail("��û�г����ţ��쿴ʲô��\n");

if (my["max_jing"] < 1 || my["max_qi"] < 1)
return notify_fail("�޷��쿴" + ob->name(1) + "��״̬��\n");

dj=ob->query("zhanling/a1")+ob->query("zhanling/a2")+ob->query("zhanling/a3")+ob->query("zhanling/a4")+ob->query("zhanling/a5")+ob->query("zhanling/a6")+ob->query("zhanling/a7")+ob->query("zhanling/a8");
//if (dj < 1) dj = 0;
djj=ob->query("zhanling/dj");
//if (djj < 1) dj = 0;
lv4=="������ͨ5��";
    if(dj>=0 && dj<100)
	{
	ob->set("zhanling/dj",0);
	}else if(dj>=100 && dj<200)
	{
	ob->set("zhanling/dj",1);
	}else if(dj>=200 && dj<300)
	{		
	ob->set("zhanling/dj",2);
	}else if(dj>=300 && dj<400)
	{		
	ob->set("zhanling/dj",3);
	}else if(dj>=400 && dj<500)
	{
	ob->set("zhanling/dj",4);
	}else if(dj>=500 && dj<600)
	{
	ob->set("zhanling/dj",5);
	}else if(dj>=600 && dj<700)
	{
	ob->set("zhanling/dj",6);
	}else if(dj>=700 && dj<800)
	{
	ob->set("zhanling/dj",7);
	}else if(dj>=800 && dj<900)
	{
	ob->set("zhanling/dj",8);
	}else if(dj>=900 && dj<1000)
	{
	ob->set("zhanling/dj",9);
	}else if(dj>=1000 && dj<1100)
	{
	ob->set("zhanling/dj",10);
	}else if(dj>=1100 && dj<1200)
	{
	ob->set("zhanling/dj",11);
	}else if(dj>=1200 && dj<1300)
	{
	ob->set("zhanling/dj",12);
	}else if(dj>=1300 && dj<1400)
	{
	ob->set("zhanling/dj",13);
	}else if(dj>=1400 && dj<1500)
	{
	ob->set("zhanling/dj",14);
	}else if(dj>=1500 && dj<1600)
	{
	ob->set("zhanling/dj",15);
	}else if(dj>=1600 && dj<1700)
	{
	ob->set("zhanling/dj",16);
	}else if(dj>=1700 && dj<1800)
	{
	ob->set("zhanling/dj",17);
	}else if(dj>=1800 && dj<1900)
	{
	ob->set("zhanling/dj",18);
	}else if(dj>=1900 && dj<2000)
	{
	ob->set("zhanling/dj",19);
	}else if(dj>=2000 && dj<2100)
	{
	ob->set("zhanling/dj",20);
	}else if(dj>=2100 && dj<2200)
	{
	ob->set("zhanling/dj",21);
	}else if(dj>=2200 && dj<2300)
	{
	ob->set("zhanling/dj",22);
	}else if(dj>=2300 && dj<2400)
	{
	ob->set("zhanling/dj",23);
	}else if(dj>=2400 && dj<2500)
	{
	ob->set("zhanling/dj",24);
	}else if(dj>=2500 && dj<2600)
	{
	ob->set("zhanling/dj",25);
	}else if(dj>=2600 && dj<2700)
	{
	ob->set("zhanling/dj",26);
	}else if(dj>=2700 && dj<2800)
	{
	ob->set("zhanling/dj",27);
	}else if(dj>=2800 && dj<2900)
	{
	ob->set("zhanling/dj",28);
	}else if(dj>=2900 && dj<3000)
	{
	ob->set("zhanling/dj",29);
	}else if(dj>=3000)
	{
	ob->set("zhanling/dj",30);
	}


//	if (me->query("vip/level"))
//	{
//	vip = ZJSIZE(25)+HIC" me->query("vip/level") ";
//	}

str = ZJOBLONG;
	str += sprintf(""CYN"����������"HIR"��"HIW"ս��ϵͳ"HIR"��"NOR""CYN"����������"HIC""NOR"\n");    
	str += sprintf(WHT"��"WHT"��������������������������������������������"WHT"��"NOR"\n");
	str += sprintf(WHT"����ǰս��ȼ�����	" NOR + YEL 					 "%d��													%s""", djj,ZJURL("cmds:zhanling")ZJSIZE(28)""WHT"ˢ��")+sprintf(HIY"" NOR + HIW " / %s""\n", ZJURL("cmds:help zhanling1")ZJSIZE(28)""WHT"����");				
//    str += sprintf(HIR"����ǰս��ȼ�����" NOR + HIY "%d �� / %s""\n", dj,ZJURL("cmds:zhanling")ZJSIZE(25)""HIW" ˢ��"+ZJURL("cmds:help vip1")ZJSIZE(25)""HIW" / �鿴��Ϊ��ȡ��ʽ");
	str += sprintf(WHT""WHT""WHT""NOR"\n");

    if(djj==0)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,100);	
	}else if(djj==1)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,200);	
	}else if(djj==2)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,300);	
	}else if(djj==3)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,400);	
	}else if(djj==4)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,500);	
	}else if(djj==5)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,600);	
	}else if(djj==6)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,700);	
	}else if(djj==7)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,800);	
	}else if(djj==8)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,900);	
	}else if(djj==9)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,1000);	
	}else if(djj==10)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,1100);	
	}else if(djj==11)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,1200);	
	}else if(djj==12)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,1300);	
	}else if(djj==13)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,1400);	
	}else if(djj==14)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,1500);	
	}else if(djj==15)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,1600);	
	}else if(djj==16)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,1700);	
	}else if(djj==17)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,1800);	
	}else if(djj==18)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,1900);	
	}else if(djj==19)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,2000);	
	}else if(djj==20)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,2100);	
	}else if(djj==21)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,2200);	
	}else if(djj==22)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,2300);	
	}else if(djj==23)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,2400);	
	}else if(djj==24)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,2500);	
	}else if(djj==25)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,2600);	
	}else if(djj==26)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,2700);	
	}else if(djj==27)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,2800);	
	}else if(djj==28)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,2900);	
	}else if(djj==29)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%d��Ϊֵ		""\n", dj,3000);	
	}else if(djj==30)
	{
	str += sprintf(WHT"��ս���������衽��	" NOR + YEL "%d/%s		""\n", dj,"���ѷⶥ");	
	}
	
	str += sprintf(WHT""WHT""WHT""NOR"\n");

	str += sprintf(WHT"���ȼ���" NOR + WHT "	������������				       """)+sprintf(HIW"���߼�������" NOR + HIR "			""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");

	str += sprintf("	1����			"ZJSIZE(33)+ZJURL("cmds:zhanlinglq 1")ZJSIZE(30)""WHT"1000��ȯ")+"						"+sprintf(ZJSIZE(33)+ZJURL("cmds:zhanlinglqq 1")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	str += sprintf(WHT""WHT""WHT""NOR"\n");

	str += sprintf("	2����		"ZJSIZE(33)+ZJURL("cmds:zhanlinglq 2")ZJSIZE(30)""WHT"1000��ȯ")+"			"+sprintf(ZJSIZE(33)+ZJURL("cmds:zhanlinglqq 2")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");

	str += sprintf("	3����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 3")ZJSIZE(30)""WHT"1000��ȯ")+"					"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 3")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	4����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 4")ZJSIZE(30)""WHT"1000��ȯ")+"							"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 4")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	5����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 5")ZJSIZE(30)""WHT"1000��ȯ")+"							"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 5")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	6����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 6")ZJSIZE(30)""WHT"1000��ȯ")+"						"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 6")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	7����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 7")ZJSIZE(30)""WHT"1000��ȯ")+"					"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 7")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	8����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 8")ZJSIZE(30)""WHT"1000��ȯ")+"									"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 8")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	9����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 9")ZJSIZE(30)""WHT"1000��ȯ")+"									"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 9")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	10����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 10")ZJSIZE(30)""WHT"1000��ȯ")+"							"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 10")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	11����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 11")ZJSIZE(30)""WHT"1000��ȯ")+"											"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 11")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	12����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 12")ZJSIZE(30)""WHT"1000��ȯ")+"											"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 12")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	13����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 13")ZJSIZE(30)""WHT"1000��ȯ")+"									"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 13")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	14����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 14")ZJSIZE(30)""WHT"1000��ȯ")+"								"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 14")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	15����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 15")ZJSIZE(30)""WHT"1000��ȯ")+"								"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 15")ZJSIZE(30)""WHT"500��ʯ+2000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	16����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 16")ZJSIZE(30)""WHT"500��ʯ")+"									"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 16")ZJSIZE(30)""WHT"1000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	17����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 17")ZJSIZE(30)""WHT"500��ʯ")+"											"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 17")ZJSIZE(30)""WHT"1000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	18����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 18")ZJSIZE(30)""WHT"500��ʯ")+"										"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 18")ZJSIZE(30)""WHT"1000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	19����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 19")ZJSIZE(30)""WHT"500��ʯ")+"							"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 19")ZJSIZE(30)""WHT"1000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	20����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 20")ZJSIZE(30)""WHT"500��ʯ")+"		                     "+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 20")ZJSIZE(30)""WHT"1000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	21����		"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 21")ZJSIZE(30)""WHT"500��ʯ")+"										"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 21")ZJSIZE(30)""WHT"1000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	22����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 22")ZJSIZE(30)""WHT"500��ʯ")+"							"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 22")ZJSIZE(30)""WHT"1000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	23����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 23")ZJSIZE(30)""WHT"500��ʯ")+"										"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 23")ZJSIZE(30)""WHT"1000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	24����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 24")ZJSIZE(30)""WHT"500��ʯ")+"							"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 24")ZJSIZE(30)""WHT"1000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	25����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 25")ZJSIZE(30)""WHT"500��ʯ")+"								"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 25")ZJSIZE(30)""WHT"1000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	26����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 26")ZJSIZE(30)""WHT"500��ʯ")+"						"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 26")ZJSIZE(30)""WHT"2000��ʯ+4000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	27����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 27")ZJSIZE(30)""WHT"500��ʯ")+"							"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 27")ZJSIZE(30)""WHT"3000��ʯ+12000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	28����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 28")ZJSIZE(30)""WHT"1500��ʯ")+"										"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 28")ZJSIZE(30)""WHT"4000��ʯ+1600��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	29����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 29")ZJSIZE(30)""WHT"3500��ʯ")+"										"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 29")ZJSIZE(30)""WHT"5000��ʯ+20000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf("	30����	"ZJSIZE(30)+ZJURL("cmds:zhanlinglq 30")ZJSIZE(30)""WHT"5000��ʯ")+"										"+sprintf(ZJSIZE(30)+ZJURL("cmds:zhanlinglqq 30")ZJSIZE(30)""WHT"10000��ʯ+50000��ȯ""\n");	
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	
//	str += sprintf(ZJSIZE(33)+WHT"	100��������"  +  "									300��������					       """)+sprintf(HIW"" NOR + HIR "			""\n");	

	str += sprintf(WHT""WHT""WHT""NOR"\n");
	str += sprintf(WHT""WHT""WHT""NOR"\n");
	
	str += sprintf(HIC"	"HIY"																					"MAG HBWHT""NOR"\n");    

//	str += sprintf(HIG"vip��Ϊ��ǩ���ͳ�ֵ��á�" NOR"\n");	
//	str += sprintf(HIY"" NOR + HIW "				%s""\n", ZJURL("cmds:help vip1")ZJSIZE(25)""BLK HBGRN" �鿴��������");

	
	
	str += sprintf(HIC"	"HIY"																					"MAG HBWHT""NOR"\n");    



str += sprintf(WHT"��"WHT"��������������������������������������������"WHT"��"NOR"\n");
//str += sprintf(""CYN"�������������������������"HIC""NOR"\n");    










str = replace_string(str,"\n",ZJBR);
if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
str = str[0..(strlen(str)-5)];
str += "\n";
message("vision", str, me);
return 1;
}


string status_color(int current, int max)
{
int percent;
if( max>0 ) percent = current * 100 / max;
else percent = 100;
if( percent > 100 ) return HIC;
if( percent >= 90 ) return HIG;
if( percent >= 60 ) return HIY;
if( percent >= 30 ) return YEL;
if( percent >= 10 ) return HIR;
return RED;
}
int potential_lv(int level)
{
int grade;
grade =level/5+1;
return grade;
}

int help(object me)
{
write(@HELP
ָ���ʽ : hp
   hp <��������>   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�ľ�, ��, ����ֵ��

see also : score
HELP
);
return 1;
}

