// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"���߱���"NOR,({"boxwg1"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"����ϵͳ������"+this_object()->query("name")+",\nʹ��(openbox boxwg1)"ZJURL("cmds:openbox boxwg1")ZJSIZE(15)"��"NOR"����!\n");
	    set("unit","��");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxwg1",1);
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
"/HELL9/BOX/box1",
"/HELL9/BOX/box2",
"/HELL9/BOX/box3",
"/HELL9/BOX/box4",
"/HELL9/BOX/box5",
"/HELL8/BOX/box1",
"/HELL8/BOX/box2",
"/HELL8/BOX/box3",
"/HELL8/BOX/box4",
"/HELL6/BOX/box1",
"/HELL6/BOX/box2",
"/HELL6/BOX/box3",
"/HELL6/BOX/box4",
"/HCSP/wzzbSP/sp1",
"/HCSP/wzzbSP/sp2",
"/HCSP/wzzbSP/sp3",
"/HCSP/wzzbSP/sp4",
"/HCSP/wzzbSP/sp5",
"/HCSP/wzzbSP/sp6",
"/HCSP/wzzbSP/sp7",
"/HCSP/wzzbSP/sp8",
"/HCSP/wzzbSP/sp9",
"/HCSP/wzzbSP/sp1",
"/HCSP/wzzbSP/sp2",
"/HCSP/wzzbSP/sp3",
"/HCSP/wzzbSP/sp4",
"/HCSP/wzzbSP/sp5",
"/HCSP/wzzbSP/sp6",
"/HCSP/wzzbSP/sp7",
"/HCSP/wzzbSP/sp8",
"/HCSP/wzzbSP/sp9",
"/HCSP/wzzbSP/sp1",
"/HCSP/wzzbSP/sp2",
"/HCSP/wzzbSP/sp3",
"/HCSP/wzzbSP/sp4",
"/HCSP/wzzbSP/sp5",
"/HCSP/wzzbSP/sp6",
"/HCSP/wzzbSP/sp7",
"/HCSP/wzzbSP/sp8",
"/HCSP/wzzbSP/sp9",
});

	object me = this_player();
	if (me->is_busy())
	      { write("����һ������δ��ɣ�\n"); return 1;}
	if( me->is_fighting() )
	      { write("ս���п����䣿����ѽ��\n"); return 1;}

	message_vision(HIG"$N�������["+this_object()->query("name")+"]�ĸ���,���仯Ϊһ����ɫ�⻪��"NOR"\n",me);
	i=random((int)sizeof(box));

	ob = new(box[i]);

    if(ob->query("base_value"))
    {
       num=random(1)+1;
       ob->set_amount(1);
    }

  tell_object(me,""HIG"*****************************************************\n");
  tell_object(me,""HIG"��ϲ: "NOR"���["+this_object()->query("name")+"]�еõ���..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIG"*****************************************************"NOR"\n");
    ob->move(me);
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}