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

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"请输入礼包码：萌新开荒"NOR,"jihuo8 $txt#")+"\n");
	switch (arg) {
	  case "萌新开荒" :
		me->add_temp("sword",1);
		write("哦豁！\n");
		message("vision","礼包码正确！"+me->name()+"！\n",me);
		
		break;
	  default :
		return notify_fail("礼包码错误，请前往官方QQ群获取输入正确的礼包码\n");

	}		
              sscanf(arg, "%s ", a);
  if(me->query("jihuom/s8")>0)
	{
		tell_object(me, HIR"每个礼包码只能使用一次！\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "领取了萌新开荒装备！"NOR);
//	me->add("combat_exp",100000);
//	me->add("clone\vip2\qilin.c",5);
//    me->add("dajif",100);
//	me->add("max_neili", 500);
//	me->add("max_jingli", 500);

	me->set("jihuom/s8",1);

//	ob = new("clone/vip2/qilin");
  //  ob->set_amount(3);
//	ob->move(me);

//	ob = new("clone/vip2/xuanling");
 //   ob->set_amount(6);
//	ob->move(me);

	ob = new("clone/GMwupin/xinshouzb/bg1");
    ob->set_amount(1);
	ob->move(me);

	ob = new("clone/GMwupin/xinshouzb/bg2");
    ob->set_amount(1); 
	ob->move(me);

	ob = new("clone/GMwupin/xinshouzb/bg3");
    ob->set_amount(1);
	ob->move(me);

	ob = new("clone/GMwupin/xinshouzb/bg8");
    ob->set_amount(1);
	ob->move(me);

	ob = new("clone/GMwupin/xinshouzb/bg11");
    ob->set_amount(1);
	ob->move(me);

	ob = new("clone/GMwupin/GMSSS8881");
    ob->set_amount(1);
	ob->move(me);
	
	ob = new("clone/GMwupin/GMSSS8882");
    ob->set_amount(1);
	ob->move(me);
	
	write("礼包码正确，你获得了以下奖励!\n");
        tell_object(me,HIW"你获得了：\n" +
        1 + "套 萌新开荒装备\n" +
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
