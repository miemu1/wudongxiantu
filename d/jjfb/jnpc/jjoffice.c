//edit by jerry
//2008.11.17

#include <ansi.h>
inherit NPC;

#define JJ_SYS "/d/jjfb/jsys/jj_sys"

int ask_job();

void create()
{

        set_name(HIW"���˸���"NOR, ({ "fuben", "shi" }));

        set("gender", "����");
        set("age", 26);
	set("inquiry", ([
        	"��ս���˸���" : (: ask_job :),
            ]));

        setup();
}

int ask_job()
{
	object me,jjmem;

	me = this_player();



	if(me->query("combat_exp") >= 1)
	{
		tell_object(me, HIG"�Ǻǡ�,��û��һ�����Ժ���˵���ɣ�\n"NOR);
        return 1;
    }

	if(JJ_SYS->query_room_amount() >= 2000)
	{
		tell_object(me,"�����Ѿ�����̫�࣬��ӭ�´β��롣\n");
		return 1;
	}
	//ɾ���ɵĸ���
	jjmem = me->query_temp("jroom/jjfb_jjmem");
	if(objectp(jjmem))
	{
		jjmem->delete("user_id");
	}
	//�����µĸ���
	me->add("menpiao",-1);
	me->apply_condition("jjfb",300);
	JJ_SYS->jjfb(me);

	return 1;
}