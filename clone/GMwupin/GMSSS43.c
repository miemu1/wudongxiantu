// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"��Ƭ����"NOR,({"boxspv1"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"����ϵͳ������"+this_object()->query("name")+",\nʹ��(openbox boxspv1)"ZJURL("cmds:openbox boxspv1")ZJSIZE(15)"��"NOR"����!\n");
	    set("unit","��");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxspv1",1);
}
//�򿪱���ĺ���
int do_openbox()
{
   int i;
   int num=1;
   string obj="";
   object ob;
 /*
   * ���,D1��װ���������,��ת
  */
   string *box=
({
"/HCSP/sp1",
"/HCSP/sp1",
"/HCSP/sp1",
"/HCSP/sp1",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp2",
"/HCSP/sp2",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp3",
"/HCSP/sp3",
"/HCSP/sp4",
"/HCSP/sp4",
"/HCSP/sp5",
"/HCSP/sp5",
"/HCSP/sp6",
"/HCSP/sp7",
"/HCSP/sp7",
"/HCSP/sp7",
"/HCSP/sp7",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp8",
"/HCSP/sp8",
"/HCSP/sp8",
"/HCSP/sp8",
"/HCSP/sp9",
"/HCSP/sp9",
"/HCSP/sp10",
"/HCSP/sp11",
"/HCSP/sp12",
"/HCSP/sp12",
"/HCSP/sp12",
"/HCSP/sp13",
"/HCSP/sp14",
"/HCSP/sp14",
"/HCSP/sp14",
"/HCSP/sp14",
"/HCSP/sp14",
"/HCSP/sp15",
"/HCSP/sp15",
"/HCSP/sp15",
"/HCSP/sp15",
"/HCSP/sp16",
"/HCSP/sp16",
"/HCSP/sp16",
"/HCSP/sp17",
"/HCSP/sp17",
"/HCSP/sp17",
"/HCSP/sp27",
"/HCSP/sp27",
"/HCSP/sp27",
"/HCSP/sp27",
"/HCSP/sp28",
"/HCSP/sp28",
"/HCSP/sp18",
"/HCSP/sp18",
"/HCSP/sp18",
"/HCSP/sp18",
"/HCSP/sp19",
"/HCSP/sp19",
"/HCSP/sp19",
"/HCSP/sp20",
"/HCSP/sp20",
"/HCSP/sp20",
"/HCSP/sp21",
"/HCSP/sp21",
"/HCSP/sp21",
"/HCSP/sp22",
"/HCSP/sp22",
"/HCSP/sp22",
"/HCSP/sp23",
"/HCSP/sp23",
"/HCSP/sp23",
"/HCSP/sp23",
"/HCSP/sp24",
"/HCSP/sp24",
"/HCSP/sp24",
"/HCSP/sp24",
"/HCSP/sp25",
"/HCSP/sp25",
"/HCSP/sp25",
"/HCSP/sp26",
"/HCSP/sp26",
"/HCSP/sp26",
"/HCSP/sp29",
"/HCSP/sp29",
"/HCSP/sp29",
"/HCSP/sp30",
"/HCSP/sp30",
"/HCSP/sp30",
});

	object me = this_player();
	if (me->is_busy())
	      { write("����һ������δ��ɣ�\n"); return 1;}
	if( me->is_fighting() )
	      { write("ս���п����䣿����ѽ��\n"); return 1;}

	message_vision(HIR"$N�������["+this_object()->query("name")+"]�ĸ���,���仯Ϊһ���ɫ�⻪��"NOR"\n",me);
	i=random((int)sizeof(box));

	ob = new(box[i]);

    if(ob->query("base_value"))
    {
       num=random(1)+1;
       ob->set_amount(1);
    }

  tell_object(me,""HIR"*****************************************************\n");
  tell_object(me,""HIR"��ϲ: "NOR"���["+this_object()->query("name")+"]�еõ���..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIR"*****************************************************"NOR"\n");
    ob->move(me);
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}