// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"筑基宝箱"NOR,({"boxsv3"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"这是系统奖励的"+this_object()->query("name")+",\n使用(openbox boxsv3)"ZJURL("cmds:openbox boxsv3")ZJSIZE(15)"打开"NOR"看看!\n");
	    set("unit","个");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxsv3",1);
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
"/SJSSS2/GW1/JL/bg1",
"/SJSSS2/GW1/JL/bg2",
"/SJSSS2/GW1/JL/bg3",
"/SJSSS2/GW1/JL/bg4",
"/SJSSS2/GW1/JL/bg6",
"/SJSSS2/GW1/JL/bg7",
"/HCSP/XianFaSuiPian",
"/SJSSS2/GW1/JL/bg8",
"/SJSSS2/GW1/JL/bg11",
"/SJSSS2/GW1/JL/bg12",
"/HCSP/sp18",
"/clone/GMwupin/GMSSS43",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp15",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp15",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp15",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp15",
"/SJSSS2/GW1/JL/bga1",
"/SJSSS2/GW1/JL/bga2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
"/SJSSS2/BOX/box2",
});

	object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}

	message_vision(HIR"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱化为一阵红色光华！"NOR"\n",me);
	i=random((int)sizeof(box));

	ob = new(box[i]);

    if(ob->query("base_value"))
    {
       num=random(1)+1;
       ob->set_amount(1);
    }

  tell_object(me,""HIR"*****************************************************\n");
  tell_object(me,""HIR"恭喜: "NOR"你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIR"*****************************************************"NOR"\n");
    ob->move(me);
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}