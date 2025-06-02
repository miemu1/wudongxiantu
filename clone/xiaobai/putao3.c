#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
void create()
{
	set_name(YEL"���Ѹ�"NOR, ({"putaogan"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 10);
            set("no_sell",1);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
		set("base_value", 100);
		set("long","����һ����ʦ����ɹ�ɵ�"YEL"���Ѹ�"NOR"��\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
int exp2;
      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

	if (me->is_fighting())
		    return notify_fail("����ս���У�����ʹ��"+ name() +"��\n");
    exp2=1400+random(201);
	players[i]->set("wenda",1);
    me->add("experience",exp2);
	CHANNEL_D->do_channel(this_object(), "chat", HIY"ʮ��������ãã"+ZJURL("cmds:wenda "+"��˼���������� "+"1497163455!")ZJSIZE(15)+"�ش�"NOR"");
	me->add("potential",exp2);
	write(YEL"�����һ��"YEL"���Ѹ�"YEL"Ǳ����ʵս���������"+exp2+"!"NOR"\n");
	add_amount(-1);
	return 1;
}