
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "���籾Դʯ" NOR, ( {"tian jings7", "tians7", "jings7"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "�ռ��������ϣ�����һ��С�������ȫ��Դ֮��̮��ѹ�����ɵ�Դʯ��"NOR"\n" );
		set("spectxt", "����װ���Ĳ��ϡ�\n");
		set("unit", "��");
		set("value", 1);
		set("tianji1", 500);
        set("no_sell",1);
		set("max_buy",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "����" NOR);
		set("can_make", "all");
		set("power_point", 10000);
	}
}

int query_autoload() { return 1; }