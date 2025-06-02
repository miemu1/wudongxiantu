#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("����", ({"land mine", "mine"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "����һ��ɱ����ǿ��ĵ��ף�С�ı�ȵ��ˡ�\n");
    set("no_sell", 1);
    set("no_give", 1);
    set("shade_vision", 1);// look ����Ӻ���
    set("unit", "��");
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
    notify_fail("ʲô��\n");
  }
  else
  {
    this_object()->set_name(HIR "(���µ�)" NOR + " ����", ({"land mine", "mine"}));
    this_object()->set("touch/on", 1);
    mid = me->query("id");
    this_object()->set("touch/id", mid);
    notify_fail("�㽫���׵ı��մ��˿�����\n");
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
    notify_fail("��о��������ֵֹġ�\n");
  }
  else
  {

    
    inv->add("qi", -10000);
    message_vision("ɲ�Ǽ䣬һ��¡��¡��������Ȼ���죬�������硣\n", me);
    message_vision("ͻȻ��$N�ҽ�һ����ԭ���ǲȵ��˵��ף�ֻ��$N��һֻ�ų���ķ�����˹�����\n", me);

    destruct(this_object());
  }
}