// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG"������Ƭ����"NOR,({"boxhl2"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"����ϵͳ������"+this_object()->query("name")+",\nʹ��(openbox boxhl2)"ZJURL("cmds:openbox boxhl2")ZJSIZE(15)"��"NOR"����!\n");
	    set("unit","��");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxhl2",1);
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
"/HCSP/jyzbSP/sp1",
"/HCSP/jyzbSP/sp2",
"/HCSP/jyzbSP/sp3",
"/HCSP/jyzbSP/sp4",
"/HCSP/jyzbSP/sp5",
"/HCSP/jyzbSP/sp6",
"/HCSP/jyzbSP/sp7",
"/HCSP/jyzbSP/sp8",
"/HCSP/jyzbSP/sp9",
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