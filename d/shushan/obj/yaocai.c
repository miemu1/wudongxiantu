//hanchat@txwx2005
inherit ITEM;
void create()
{
	set_name("�ϵ�ҩ��", ({ "yaocai", "cai" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",
			"������ɽɽ����ϡ��ҩ��,��������������϶��ǳ���Ч�á�\n" );
		set("unit", "��");
		set("value", 1);
	}
}