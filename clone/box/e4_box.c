// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIM"逍遥宝箱"NOR,({"boxno3"}));
	set_weight(5000);
       
	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"这是系统奖励的"+this_object()->query("name")+",\n使用(openbox boxno3)"ZJURL("cmds:openbox boxno3")ZJSIZE(15)"打开"NOR"看看!\n");
	    set("unit","个");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxno3",1);
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
"/clone/new/e4/e4_arrmor","/clone/new/e4/e4_finger","/clone/new/e4/e4_hands","/clone/new/e4/e4_head","/clone/new/e4/e4_pants","/clone/new/e4/e4_sword","/clone/new/e4/e4_neck",
});
  
	object me = this_player();
	if (me->is_busy())
	      { write("你上一个动作未完成！\n"); return 1;}
	if( me->is_fighting() )
	      { write("战斗中开宝箱？挨宰呀？\n"); return 1;}
       
	message_vision(HIM"$N轻轻打开了["+this_object()->query("name")+"]的盖子,宝箱化为一阵紫色光华！"NOR"\n",me);
	i=random((int)sizeof(box));
    
	ob = new(box[i]); 
   
    if(ob->query("base_value"))
    {
       num=random(5)+1;
       ob->set_amount(num);
    }
    
  tell_object(me,""HIM"*****************************************************\n");
  tell_object(me,""HIR"恭喜: "NOR"你从["+this_object()->query("name")+"]中得到了..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIM"*****************************************************"NOR"\n");
    ob->move(me); 
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}