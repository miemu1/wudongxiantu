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

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"请输入礼包码：删档补偿B"NOR,"jihuo9 $txt#")+"\n");
	switch (arg) {
	  case "删档补偿B" :
		me->add_temp("sword",1);
		write("哦豁！\n");
		message("vision","礼包码正确！"+me->name()+"！\n",me);
		
		break;
	  default :
		return notify_fail("礼包码错误，请前往官方QQ群获取输入正确的礼包码\n");

	}		
              sscanf(arg, "%s ", a);
  if(me->query("jihuom/s9")>0)
	{
		tell_object(me, HIR"每个礼包码只能使用一次！\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "领取了删档补偿B！"NOR);
	me->add("combat_exp",5000000);
//	me->add("clone\vip2\qilin.c",5);
    me->add("dajif",500);
//	me->add("max_neili", 500);
//	me->add("max_jingli", 500);

	me->set("jihuom/s9",1);

//	ob = new("clone/vip2/qilin");
  //  ob->set_amount(3);
//	ob->move(me);

//	ob = new("clone/vip2/xuanling");
 //   ob->set_amount(6);
//	ob->move(me);


//	ob = new("clone/good/qianghua_crystal");
//    ob->set_amount(1);
//	ob->move(me);
	
	ob = new("clone/good/practice-emblem");
    ob->set_amount(1);
	ob->move(me);
	
	write("礼包码正确，你获得了以下奖励!\n");
        tell_object(me,HIW"你获得了：\n" +
        500 + "万修为\n" +
        500 + "钻石\n" +
        1 + "紫金练习勋章\n" +
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
