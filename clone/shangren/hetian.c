//yupei.c
#include <ansi.h>

#include <armor.h>

inherit SHIELD;
string do_wear();
string do_remove();
void create()
{
	set_name(HIY"��������"NOR, ({"yu pei"}));
	set_weight(800);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("value", 100);
		set("long", "һö�ɺ������Ƴɵ����壬����������������ů�������ģ�\n");
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("material", "steel");
		set("wear_msg", (: do_wear :)); 
		set("remove_msg", (: do_remove :)); 
	set("armor_prop/dodge", 1);
	set("armor_prop/armor", 20);
	}

	setup();
}

int query_autoload() { return 1; }

string do_wear()
{   object me = this_player();
     me->set_temp("suit_eff/constitution",2);
}
string do_remove()
{   object me = this_player();
     me->set_temp("suit_eff/constitution",0);
}
