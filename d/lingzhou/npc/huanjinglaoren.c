//edit by jerry
//2008.11.17
/*
�����˵��˸����Ľӿ�
by Ц��
*/
#include <ansi.h>
inherit NPC;

string do_fly() ;
#define J_SYS "/d/jfbb/sys/j_sys"
#define J_SYY "/d/jfbc/sys/j_sys"
#define J_SYZ "/d/jfbd/sys/j_sys"
int ask_job();
int ask_xinmo();
int ask_huanmo();
string ask_jobb();
string ask_mj();
string huanmo();

void create()
{

        set_name(HIW"�þ�����"NOR, ({ "yi mei", "dao shi" }));
        set("title", HIW"�����ƻ�"NOR);

        set("gender", "����");
        set("age", 100);
        set("long","�����ξ������һ����\n");

	set("inquiry", ([ 
        	"�����ܶ�": (: ask_job :),
		    "�����ܶ�": (:ask_xinmo:),
			"��ħ�ܶ�": (:ask_huanmo:),
            ])); 

        setup();
}
void init()
{
	add_action("fly","fly");
}
string do_fly()
{
	write(ZJOBLONG"���͸�����\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)+
		"ɱ�տ�:fly japan"ZJSEP
	//	"�ڿ�:fly lvliu"ZJSEP
	//	"����ռ�:fly qiyi"ZJSEP	
		"��ʬ����:fly jiangshi"ZJSEP
		"��������:fly dongfang"ZJSEP
		"��������:fly daojian"ZJSEP
		"����ռ�:fly qiyi\n");
		return "������";
}
int fly(string arg)
{
	object me=this_player();
	write("�ٺ٣�С�ı���ˣ�����\n");
	if (arg=="japan") me->move("/d/japan/dadao1");
	else if (arg=="qiyi") me->move("/d/city/qiyi");
	else if (arg=="lvliu") me->move("/u/rock/weapon/kuang");
	else if (arg=="dongfang") me->move("/maze/dongfang/fightroom");
	else if (arg=="daojian") me->move("/maze/daojian/fightroom");	
	else if (arg=="jiangshi") me->move("/maze/jiangshi/fightroom");
	else if (arg=="shenlin") me->move("/maze/forestnew/enter");
	else write(HIR"\n������û�������"NOR"\n");
	return 1;
}
int ask_job()
{
	object me;
	object *team,jmem;
	int i,size;	
int last;
	me = this_player();
		team = me->query_team();//���������
	size = sizeof(team);//ȡ����
	//ɾ���ɵĸ���
 
	last = me -> query("snakeSign");
	jmem = me->query_temp("room/jfbb_jmem");
	if(time()/600 == last/600){
write("��"+HIY+((last+600-time())/60)+NOR+"���Ӻ�������\n");
		return 1;
	}
	if(objectp(jmem))//�����ʶ
	{
		jmem->delete("user_id");
	}
	if(size > 1)//�Ƿ��Ƕ���
	{
		tell_object(me,"�����ܶ�ֻ�ܵ��˽��롣\n");
	} me->set("snakeSign",time());
		J_SYS->jfbb(me);//�����µĸ���
	return 1;
}

int ask_xinmo()
{
	object me;
	object *team,jmee;
	int i,size;	
int last;
	me = this_player();
		team = me->query_team();//���������
	size = sizeof(team);//ȡ����
	//ɾ���ɵĸ���
 
	last = me -> query("snakeSignl");
	jmee = me->query_temp("room/jfbc_jmee");
	if(time()/600 == last/600){
write("��"+HIY+((last+600-time())/60)+NOR+"���Ӻ�������\n");
		return 1;
	}
	if(objectp(jmee))//�����ʶ
	{
		jmee->delete("user_id");
	}
	if(size > 1)//�Ƿ��Ƕ���
	{
		tell_object(me,"�����ܶ�ֻ�ܵ��˽��롣\n");
	} me->set("snakeSignl",time());
		J_SYY->jfbc(me);//�����µĸ���
	return 1;
}

int ask_huanmo()
{
	object me;
	object *team,jmed;
	int i,size;	
int last;
	me = this_player();
		team = me->query_team();//���������
	size = sizeof(team);//ȡ����
	//ɾ���ɵĸ���
 
	last = me -> query("snakeSignn");
	jmed = me->query_temp("room/jfbd_jmed");
	if(time()/600 == last/600){
write("��"+HIY+((last+600-time())/60)+NOR+"���Ӻ�������\n");
		return 1;
	}
	if(objectp(jmed))//�����ʶ
	{
		jmed->delete("user_id");
	}
	if(size > 1)//�Ƿ��Ƕ���
	{
		tell_object(me,"��ħ�ܶ�ֻ�ܵ��˽��롣\n");
	} me->set("snakeSignn",time());
		J_SYZ->jfbd(me);//�����µĸ���
	return 1;
}

