//shushan2 by yushu@SHXY 2000.12
inherit ITEM;
#define BYAOCAO       "/d/shushan/obj/yaocai"
void create()
{
  set_name("��¯", ({ "jin danlu", "danlu" }) );
  set_weight(300000);
  set_max_encumbrance(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "����һ���������������Ĵ��¯, �������(liandan)�����Ƶ�ҩ��\n");
    set("value", 2000);
  }
}

void init()
{
	add_action("do_liandan", "liandan");
}

int do_liandan()
{
	object yaocai, lingyao;
	object me=this_player();
	if(!yaocai=present("yaocai", me))
		return notify_fail("������û��ҩ��...������ʲô����!\n");
	if(base_name(yaocai)!=BYAOCAO)
		return notify_fail("�ٺ�...��������? ��ϧhanchat�ܴ���Ŷ!\n");
	if(me->query_skill("force", 1)<1000)
		return notify_fail("��Ļ����ڹ�̫���ˣ�û�취�����������̵��ȶȡ�\n");
	if(me->query("eff_qi")<1000)
		return notify_fail("���Ѿ������ˣ���һѪ������¯��ô��,���ǿ�ȥ���˰�!\n");
	message_vision ("$N�����ϵ�ҩ��Ͷ���¯����ʼ������������\n",me);
	me->start_busy(20);
	if(random(10)>8)
	{
		tell_object(me, "��ҩ���Ƴɹ���\n");
		lingyao=new("/d/shushan/obj/lingyao");
		lingyao->move(me);
		destruct(yaocai);
		return 1;	
	}
	else
	{
		tell_object(me, "��һ�����񱻽�¯�ڵ������һ�������ˣ�\n");
		me->set("eff_qi", 100);
		return 0;
	}
}

