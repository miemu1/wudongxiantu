#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("地雷", ({"land mine", "mine"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "这是一颗杀伤力强大的地雷，小心别踩到了。\n");
    set("no_sell", 1);
    set("no_give", 1);
    set("shade_vision", 1);// look 中添加忽略
    set("unit", "颗");
    set("value", 10);
  }
  setup();
}
void init()
{
  object me;
  me = this_player();
  add_action("do_touch", "touch");
  if (me->environment())
    return 0;
  call_out("bob", 1, me);
}
void do_touch(string arg)
{
  object me;
  string mid;
  me = this_player();
  if (arg != "on")
  {
    notify_fail("什么？\n");
  }
  else
  {
    this_object()->set_name(HIR "(埋下的)" NOR + " 地雷", ({"land mine", "mine"}));
    this_object()->set("touch/on", 1);
    mid = me->query("id");
    this_object()->set("touch/id", mid);
    notify_fail("你将地雷的保险打了开来。\n");
  }
}
void bob()
{
  int i, max;
  object me, obj, *inv;
  me = this_player();
  obj = this_object();
  i = random(50) + 1;
  if ((me->query("id")) == (obj->query("touch/id")))
    return 0;
  if (obj->query("touch/on") < 1)
    return 0;

  if (i < 45)
  {
    notify_fail("你感觉到附近怪怪的。\n");
  }
  else
  {

    
    inv->add("qi", -10000);
    message_vision("刹那间，一阵「隆～隆～～」轰然巨响，尘灰四溢。\n", me);
    message_vision("突然间$N惨叫一声，原来是踩到了地雷，只见$N的一只脚朝你的方向飞了过来。\n", me);

    destruct(this_object());
  }
}