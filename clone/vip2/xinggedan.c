#include <ansi.h>

inherit ITEM;
//int effect;

void create()
{
	set_name(HIG "�Ը�" NOR, ({ "effect dan", "xgdan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "�Ը�ת��������ɸ���Ӱ�죬�������ǡ�\n");
                set("yuanbao", 3000);
		set("unit", "��");
		set("only_do_effect", 1);
	}
}
void init()
{
	add_action("effect","effect");
}
string do_effect(object me)
{
write(ZJOBLONG"��ѡ���Ը�\n"
		ZJOBACTS2+ZJMENUF(2,2,6,30)+
"������:effect ������"ZJSEP
		"��������:effect ��������"ZJSEP
		"���ռ�թ:effect ���ռ�թ"ZJSEP
		"�ĺ�����:effect �ĺ�����"ZJSEP
		"�����ڴ�:effect ��");
		return "������";
}

int effect(string arg)
{
	object me = this_player();
//	 this_player()->delete_temp("maze");
	if (arg=="������") 
	  { me->set("character", "������");
	  write("�Ը�ת���ɹ�!\n");
	   	destruct(this_object());}
	else
	 if (arg=="��������") 
	{   me->set("character", "��������");
	write("�Ը�ת���ɹ�!\n");
	   	destruct(this_object());}
	else 
	if (arg=="�ĺ�����") 
{	 me->set("character", "�ĺ�����");
write("�Ը�ת���ɹ�!\n");
	 	destruct(this_object());}
	else 
	if (arg=="���ռ�թ") 
	{ me->set("character", "���ռ�թ");
	write("�Ը�ת���ɹ�!\n");
		destruct(this_object());}
		else 	
{	write(HIR"\n�����ڴ����Ը�"NOR"\n");	}	
	return 1;
}

int query_autoload() { return 1; }


