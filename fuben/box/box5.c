// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"武者宝箱"NOR,({"boxwg1"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"这是系统奖励的"+this_object()->query("name")+",\n使用(openbox boxwg1)"ZJURL("cmds:openbox boxwg1")ZJSIZE(15)"打开"NOR"看看!\n");
	    set("unit","个");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxwg1",1);
}
//打开宝箱的函数
int do_openbox()
{
   int i;
   int num=1;
   string obj="";
   object ob;
 /*
   * 金块,D1套装，打造材料,九转
  */
   string *box=
({
"/HELL9/BOX/box1",
"/HELL9/BOX/box2",
"/HELL9/BOX/box3",
"/HELL9/BOX/box4",
"/HELL9/BOX/box5",
"/HELL8/BOX/box1",
"/HELL8/BOX/box2",
"/HELL8/BOX/box3",
"/HELL8/BOX/box4",
"/HELL6/BOX/box1",
"/HELL6/BOX/box2",
"/HELL6/BOX/box3",
"/HELL6/BOX/box4",
"/HCSP/wzzbSP/sp1",
"/HCSP/wzzbSP/sp2",
"/HCSP/wzzbSP/sp3",
"/HCSP/wzzbSP/sp4",
"/HCSP/wzzbSP/sp5",
"/HCSP/wzzbSP/sp6",
"/HCSP/wzzbSP/sp7",
"/HCSP/wzzbSP/sp8",
"/HCSP/wzzbSP/sp9",
"/HCSP/wzzbSP/sp1",
"/HCSP/wzzbSP/sp2",
"/HCSP/wzzbSP/sp3",
"/HCSP/wzzbSP/sp4",
"/HCSP/wzzbSP/sp5",
"/HCSP/wzzbSP/sp6",
"/HCSP/wzzbSP/sp7",
"/HCSP/wzzbSP/sp8",
"/HCSP/wzzbSP/sp9",
"/HCSP/wzzbSP/sp1",
"/HCSP/wzzbSP/sp2",
"/HCSP/wzzbSP/sp3",
"/HCSP/wzzbSP/sp4",
"/HCSP/wzzbSP/sp5",
"/HCSP/wzzbSP/sp6",
"/HCSP/wzzbSP/sp7",
"/HCSP/wzzbSP/sp8",
"/HCSP/wzzbSP/sp9",
});

	object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}

	message_vision(HIG"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱化为一阵紫色光华！"NOR"\n",me);
	i=random((int)sizeof(box));

	ob = new(box[i]);

    if(ob->query("base_value"))
    {
       num=random(1)+1;
       ob->set_amount(1);
    }

  tell_object(me,""HIG"*****************************************************\n");
  tell_object(me,""HIG"恭喜: "NOR"你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIG"*****************************************************"NOR"\n");
    ob->move(me);
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}