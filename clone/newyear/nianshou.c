
#include <ansi.h>
inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void create()
{
	set_name(HIY "�����ٻ���" NOR, ({ "nianshou card" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�ž����Ľ�ɫ��Ƭ�����滭��һ�����޵�ͼ����\n");
		set("base_value", 1000);
		set("base_weight", 1);
		set("base_unit", "��");
		set("only_do_effect", 1);
	}
	set_amount(1);
	setup();
}



int do_effect(object me)
{
	
	object nianshou;
	nianshou = new("clone/shizhe/nianshou");
      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");

	nianshou->move(environment(me));
	
	//message_vision("channel", HIR"��������:"HIY"��˵"+HIG+me->query("name")+HIY"�ٻ��������ޣ�"NOR"\n", users());
	//message_vision(CYN "$N" CYN "ʹ����"+query("unit")+"" + name() + CYN "���ٻ��������ޡ�"NOR"\n", me);
	CHANNEL_D->do_channel( this_object(), "chat","��˵"+me->query("name")+"ʹ����"+this_object()->query("name")+""HIC"���ٻ���"HIR"���ޣ�");
        
	add_amount(-1);
	return 1;
}