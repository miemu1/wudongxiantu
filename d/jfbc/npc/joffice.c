//edit by jerry
//2008.11.17
/*
�����˵��˸����Ľӿ�
by Ц��
*/
#include <ansi.h>
inherit NPC;

#define J_SYS "/d/jfbb/sys/j_sys"
int ask_job();
string ask_jobb();
string ask_mj();

void create()
{

        set_name(HIW"һü����"NOR, ({ "yi mei", "dao shi" }));
        set("title", HIW"ɥʬ������"NOR);

        set("gender", "����");
        set("age", 26);
        set("long","éɽ�ɴ��� һλС�������ĵ�ʿ��\n");

	set("inquiry", ([ 
        	"�����ܶ�" : (: ask_job :),
        	"�����ؾ�" : (: ask_mj :),
   	    	"ˮ䰴�" : (: ask_jobb :),
            ])); 

        setup();
}

int ask_job()
{
	object me;
	object *team,jmem;
	int i,size;	
	me = this_player();
		team = me->query_team();//���������
	size = sizeof(team);//ȡ����
	//ɾ���ɵĸ���
	jmem = me->query_temp("room/jfbb_jmem");
	if(objectp(jmem))//�����ʶ
	{
		jmem->delete("user_id");
	}
	if(size > 1)//�Ƿ��Ƕ���
	{
		tell_object(me,"�����ܶ�ֻ�ܵ��˽��롣\n");
	}
		J_SYS->jfbb(me);//�����µĸ���
	return 1;
}

string ask_jobb()
{
object me = this_player();
object man;
man = new("/d/fuben/108man/npc/1");
if (me->query("fuben/sf")<1)
return "���ˮ䰴�������������";
if (me->query("balance") < 1000000)
return "������д���100���ƽ�";
 me->add("fuben/sf",-1);
 me->add("balance",-1000000);
	MAZE_D->enter_maze(this_player(), "fuben");
	man->move(environment(me));
		return "���븱���ɹ���";
}
string ask_mj()
{
object me = this_player();
"adm/daemons/mjd"->playermove(me);
return "\n";
}