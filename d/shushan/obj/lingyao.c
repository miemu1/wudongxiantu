//hanchat@txwx2005
inherit ITEM;
void create()
{
	set_name("��ҩ", ({ "ling yao", "yao" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"���������Ƴ�������ҩ,��֪���ж��Ĺ�Ч��\n" );
		set("unit", "��");
		set("value", 1000);
	}
}