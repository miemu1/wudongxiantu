// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW"ľ����"NOR,({"ľ����"}));
	set_weight(1);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"��Сľ�������ǻҳ���ճ����úм��ݣ����ƺ����԰���"ZJURL("cmds:�� ľ����")ZJSIZE(15)"��"NOR"����!\n");
	    set("unit","��");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","�� ľ����",1);
}
//�򿪱���ĺ���
int do_openbox()
{
   object ob;

	object me = this_player();
	if (me->is_busy())
	      { write("����һ������δ��ɣ�\n"); return 1;}
	if( me->is_fighting() )
	      { write("�ȸɵ������ٿ����١�\n"); return 1;}

	message_vision(HIM"$N���ִ�["+this_object()->query("name")+"]����������һ���飬��д��ħ��ҽ�������֣���ǯ�ӽҿ���ҳ����д������С�֣��������ͼ�����е��ǵ�ͼ���е���ҩ��ͼ����"NOR"\n",me);	
		ob = new("/clone/book/mojiao");
		ob->move(me);
		write(HIG"��õ���һ��ħ��ҽ���� "NOR"\n");
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}