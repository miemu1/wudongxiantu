//edit by jerry
//2008.11.17
/*
增加了单人副本的接口
by 笑世
*/
#include <ansi.h>
inherit NPC;

#define J_SYS "/d/sangshidong/sys/j_sys"

int ask_job();

void create()
{

        set_name(HIW"一眉道人"NOR, ({ "yi mei", "dao shi" }));
        set("title", HIW"丧尸清理者"NOR);

        set("gender", "男性");
        set("age", 26);
        set("long","茅山派传人 一位小有名气的道士。\n");

	set("inquiry", ([
        	"丧尸密洞" : (: ask_job :),
            ]));

        setup();
}

int ask_job()
{
	object me;
	object *team,jmem;
	int i,size;

	me = this_player();
		team = me->query_team();//队伍的阵列
	size = sizeof(team);//取个数
		if(J_SYS->query_room_amount() >= 100)
	{
	tell_object(me,"镜像已经开启太多，欢迎下次参与。\n");
		return 1;
	}
	//删除旧的副本
	jmem = me->query_temp("room/jfbb_jmem");
	if(objectp(jmem))
	{
		jmem->delete("user_id");
	}
	if(size > 1)//是否是队伍
	{
	if(!me->is_team_leader())
		tell_object(me,"你不是领队。\n");
			if(!pointerp(team) || size < 5)
	{
		tell_object(me,"你的人手不够。\n");
		return 1;
	}
		for(i = 0;i<size;i++)
	{
		if(!team[i])
		 continue;
                if (team[i]->query("jym_level/level") >= 101)
                {
                	tell_object(me, HIY"呵呵～,50还来这里做什么!!留给小朋友去玩好了!!!!!!"NOR);
                 	return 1;
                }
        }
J_SYS->jfbbs(team,me);
	}
	else
		J_SYS->jfbb(me);//创建新的副本
	return 1;
}