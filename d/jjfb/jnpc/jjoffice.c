//edit by jerry
//2008.11.17

#include <ansi.h>
inherit NPC;

#define JJ_SYS "/d/jjfb/jsys/jj_sys"

int ask_job();

void create()
{

        set_name(HIW"单人副本"NOR, ({ "fuben", "shi" }));

        set("gender", "男性");
        set("age", 26);
	set("inquiry", ([
        	"挑战个人副本" : (: ask_job :),
            ]));

        setup();
}

int ask_job()
{
	object me,jjmem;

	me = this_player();



	if(me->query("combat_exp") >= 1)
	{
		tell_object(me, HIG"呵呵～,你没到一百万，以后再说来吧！\n"NOR);
        return 1;
    }

	if(JJ_SYS->query_room_amount() >= 2000)
	{
		tell_object(me,"镜像已经开启太多，欢迎下次参与。\n");
		return 1;
	}
	//删除旧的副本
	jjmem = me->query_temp("jroom/jjfb_jjmem");
	if(objectp(jjmem))
	{
		jjmem->delete("user_id");
	}
	//创建新的副本
	me->add("menpiao",-1);
	me->apply_condition("jjfb",300);
	JJ_SYS->jjfb(me);

	return 1;
}