// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/u/aliyun/obj/bao"
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
	    object obj,ob;
        int count,mengxin;
        string a;
		me = this_player();
        if (! arg) 

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"请输入礼包码：萌新礼包"NOR,"jihuo1 $txt#")+"\n");
	switch (arg) {
	  case "萌新礼包" :
		me->add_temp("sword",1);
		write("哦豁！\n");
		message("vision","礼包码正确，欢迎来到武动仙途MUD！"+me->name()+"！\n",me);
		
		break;
	  default :
		return notify_fail("礼包码错误，请前往官方QQ群获取输入正确的礼包码\n");

	}		
              sscanf(arg, "%s ", a);

  if(me->query("combat_exp")>5000000)
	{
		tell_object(me, HIR"你的修为超过500万，不算是萌新了！\n"NOR);
        return 1;
	}

  if(me->query("jihuom/s1")>0)
	{
		tell_object(me, HIR"每个礼包码只能使用一次！\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "初涉江湖，激活了萌新礼包码！"NOR);
	me->add("combat_exp",1000000);
	me->add("potential",5000000);
	me->add("max_neili", 1000);
	me->add("max_jingli", 1000);
	me->add("jifeng", 500);

	me->set("jihuom/s1",1);

	ob = new("clone/tianji1/xuemaid");
    ob->set_amount(1);
	ob->move(me);

	ob = new("clone/jifeng/1shimen");
    ob->set_amount(1);
	ob->move(me);

	ob = new("clone/jifeng/1bt");
    ob->set_amount(1);
	ob->move(me);

	ob = new("clone/tianji1/0qnvip");
    ob->set_amount(1);
	ob->move(me);
	write("礼包码正确，你获得了萌新奖励!\n");
        tell_object(me,HIW"你获得了：\n" +
        100 + "万修为\n" +
		500 + "万潜能\n" +
		500 + "点券\n" +
        1000+ "内力上限和精力上限。\n"+
        1 + "颗八龙血脉丹。\n"+
        1 + "张三倍潜能月卡。\n"+
        1 + "张自动师门。\n"+
        1 + "颗BT丹。\n"+
        NOR);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家红包。
HELP
        );
        return 1;
}
