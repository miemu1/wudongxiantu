//edit by jerry
//2008.11.17
/*
�����˵��˸����Ľӿ�
by Ц��
*/
#include <ansi.h>
inherit NPC;

#define J_SYS "/d/sangshidong/sys/j_sys"

int ask_job();

void create()
{

        set_name(HIW"һü����"NOR, ({ "yi mei", "dao shi" }));
        set("title", HIW"ɥʬ������"NOR);

        set("gender", "����");
        set("age", 26);
        set("long","éɽ�ɴ��� һλС�������ĵ�ʿ��\n");

	set("inquiry", ([
        	"ɥʬ�ܶ�" : (: ask_job :),
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
		if(J_SYS->query_room_amount() >= 100)
	{
	tell_object(me,"�����Ѿ�����̫�࣬��ӭ�´β��롣\n");
		return 1;
	}
	//ɾ���ɵĸ���
	jmem = me->query_temp("room/jfbb_jmem");
	if(objectp(jmem))
	{
		jmem->delete("user_id");
	}
	if(size > 1)//�Ƿ��Ƕ���
	{
	if(!me->is_team_leader())
		tell_object(me,"�㲻����ӡ�\n");
			if(!pointerp(team) || size < 5)
	{
		tell_object(me,"������ֲ�����\n");
		return 1;
	}
		for(i = 0;i<size;i++)
	{
		if(!team[i])
		 continue;
                if (team[i]->query("jym_level/level") >= 101)
                {
                	tell_object(me, HIY"�Ǻǡ�,50����������ʲô!!����С����ȥ�����!!!!!!"NOR);
                 	return 1;
                }
        }
J_SYS->jfbbs(team,me);
	}
	else
		J_SYS->jfbb(me);//�����µĸ���
	return 1;
}