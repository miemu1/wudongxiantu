//edit by jerry
//2008.11.17
/*
增加了单人副本的接口
by 笑世
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

        set_name(HIW"幻境老人"NOR, ({ "yi mei", "dao shi" }));
        set("title", HIW"如梦似幻"NOR);

        set("gender", "男性");
        set("age", 100);
        set("long","生于梦境，虚幻一生。\n");

	set("inquiry", ([ 
        	"幻心密洞": (: ask_job :),
		    "幻梦密洞": (:ask_xinmo:),
			"幻魔密洞": (:ask_huanmo:),
            ])); 

        setup();
}
void init()
{
	add_action("fly","fly");
}
string do_fly()
{
	write(ZJOBLONG"传送副本：\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)+
		"杀日寇:fly japan"ZJSEP
	//	"挖矿场:fly lvliu"ZJSEP
	//	"奇异空间:fly qiyi"ZJSEP	
		"僵尸道长:fly jiangshi"ZJSEP
		"东方不败:fly dongfang"ZJSEP
		"刀剑传奇:fly daojian"ZJSEP
		"奇异空间:fly qiyi\n");
		return "。。。";
}
int fly(string arg)
{
	object me=this_player();
	write("嘿嘿，小心别挂了！！！\n");
	if (arg=="japan") me->move("/d/japan/dadao1");
	else if (arg=="qiyi") me->move("/d/city/qiyi");
	else if (arg=="lvliu") me->move("/u/rock/weapon/kuang");
	else if (arg=="dongfang") me->move("/maze/dongfang/fightroom");
	else if (arg=="daojian") me->move("/maze/daojian/fightroom");	
	else if (arg=="jiangshi") me->move("/maze/jiangshi/fightroom");
	else if (arg=="shenlin") me->move("/maze/forestnew/enter");
	else write(HIR"\n根本就没这个副本"NOR"\n");
	return 1;
}
int ask_job()
{
	object me;
	object *team,jmem;
	int i,size;	
int last;
	me = this_player();
		team = me->query_team();//队伍的阵列
	size = sizeof(team);//取个数
	//删除旧的副本
 
	last = me -> query("snakeSign");
	jmem = me->query_temp("room/jfbb_jmem");
	if(time()/600 == last/600){
write("请"+HIY+((last+600-time())/60)+NOR+"分钟后再来！\n");
		return 1;
	}
	if(objectp(jmem))//清除标识
	{
		jmem->delete("user_id");
	}
	if(size > 1)//是否是队伍
	{
		tell_object(me,"幻心密洞只能单人进入。\n");
	} me->set("snakeSign",time());
		J_SYS->jfbb(me);//创建新的副本
	return 1;
}

int ask_xinmo()
{
	object me;
	object *team,jmee;
	int i,size;	
int last;
	me = this_player();
		team = me->query_team();//队伍的阵列
	size = sizeof(team);//取个数
	//删除旧的副本
 
	last = me -> query("snakeSignl");
	jmee = me->query_temp("room/jfbc_jmee");
	if(time()/600 == last/600){
write("请"+HIY+((last+600-time())/60)+NOR+"分钟后再来！\n");
		return 1;
	}
	if(objectp(jmee))//清除标识
	{
		jmee->delete("user_id");
	}
	if(size > 1)//是否是队伍
	{
		tell_object(me,"幻梦密洞只能单人进入。\n");
	} me->set("snakeSignl",time());
		J_SYY->jfbc(me);//创建新的副本
	return 1;
}

int ask_huanmo()
{
	object me;
	object *team,jmed;
	int i,size;	
int last;
	me = this_player();
		team = me->query_team();//队伍的阵列
	size = sizeof(team);//取个数
	//删除旧的副本
 
	last = me -> query("snakeSignn");
	jmed = me->query_temp("room/jfbd_jmed");
	if(time()/600 == last/600){
write("请"+HIY+((last+600-time())/60)+NOR+"分钟后再来！\n");
		return 1;
	}
	if(objectp(jmed))//清除标识
	{
		jmed->delete("user_id");
	}
	if(size > 1)//是否是队伍
	{
		tell_object(me,"幻魔密洞只能单人进入。\n");
	} me->set("snakeSignn",time());
		J_SYZ->jfbd(me);//创建新的副本
	return 1;
}

