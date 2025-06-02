#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload()
{
	return query_amount() + "";
}

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
        set_name(HIC "Ԫ���" NOR, ({"yuanshen guo", "guo"}));
      set("suit_point", 100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIC "����һ����ɫ���ɹ������ú�����ǿԪ����Ϊ��\n" NOR);
		set("unit", "��");
		set("base_unit", "��");
		set("base_weight", 10);
				set("no_sell", 1);
				set("no_steal", 1);
                        set("no_give",1);
                        set("no_drop",1);
				set("yuanbao",50);
                set("no_put", 1);
		set("unique",1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
        int exp;
        exp = 1000;

        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
			

        me->add("yuanshen/exp", exp);

        me->save();

        tell_object(me, HIG "�����һ��Ԫ�����Ԫ����Ϊ���ӣ�" + sprintf("%d", exp) + "�㡣\n");

        log_file("yuanshen-guoo", me->query("id") + " at " + ctime(time()) + " use yuanshen guo.\n");

	add_amount(-1);
	        if (query_amount() < 1)
                destruct(this_object());
	return 1;
}
