// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"���屦��"NOR,({"boxsv13"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"����ϵͳ������"+this_object()->query("name")+",\nʹ��(openbox boxsv13)"ZJURL("cmds:openbox boxsv13")ZJSIZE(15)"��"NOR"����!\n");
	    set("unit","��");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxsv13",1);
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
"/SJSSS7/GW1/JL/bg1",
"/SJSSS7/GW1/JL/bg2",
"/SJSSS7/GW1/JL/bg3",
"/SJSSS7/GW1/JL/bg4",
"/SJSSS7/GW1/JL/bg6",
"/SJSSS7/GW1/JL/bg7",
"/SJSSS7/GW1/JL/bg8",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp21",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp21",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp21",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp21",
"/clone/GMwupin/GMSSS43",
"/SJSSS7/GW1/JL/bg11",
"/SJSSS7/GW1/JL/bg12",
"/HCSP/XianFaSuiPian",
"/SJSSS7/GW1/JL/bga1",
"/SJSSS7/GW1/JL/bga2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/HCSP/sp18",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
"/SJSSS7/BOX/box2",
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