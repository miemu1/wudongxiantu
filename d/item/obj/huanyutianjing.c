
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "����쾧" NOR, ( {"tian jing", "tian", "jing"}));
	set_weight(250);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", HIW "�ռ��������ϣ�����һ�鴿��ɫ��ˮ������Ө��͸����Ͼ�ı�����"
		    "��ҫ�۵Ĺ������з·��̲���ǧǧ���������������������Ϣ��ɢ������������������"
		    "�Ǵ�˵�е�������������쾧���ഫΪŮ����������ơ�"NOR"\n" );
		set("spectxt", "����װ���Ĳ��ϡ�\n");
		set("unit", "��");
		set("value", 100);
		set("tianji1", 25);
        set("no_sell",1);
		set("item_origin", 1);
		set("material_attrib", "silk");
		set("material_name", HIW "���" NOR);
		set("can_make", "all");
		set("power_point", 1400);
	}
}

int query_autoload() { return 1; }