// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"���籦��"NOR,({"Aboxa1"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"����ϵͳ������"+this_object()->query("name")+",\nʹ��(openbox Aboxa1)"ZJURL("cmds:openbox Aboxa1")ZJSIZE(15)"��"NOR"����!\n");
	    set("unit","��");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox Aboxa1",1);
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
"/Aboss2/GW1/JL/bg1",
"/Aboss2/GW1/JL/bg2",
"/Aboss2/GW1/JL/bg3",
"/Aboss2/GW1/JL/bg4",
"/Aboss2/GW1/JL/bg6",
"/Aboss2/GW1/JL/bg7",
"/Aboss2/GW1/JL/bg8",
"/Aboss2/GW1/JL/jns",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp31",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp31",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp31",
"/HCSP/sp1",
"/HCSP/sp2",
"/HCSP/sp3",
"/HCSP/sp7",
"/HCSP/sp8",
"/HCSP/sp31",
"/clone/GMwupin/GMSSS43",
"/Aboss2/GW1/JL/bg11",
"/Aboss2/GW1/JL/bg12",
"/HCSP/XianFaSuiPian",
"/Aboss2/GW1/JL/bga1",
"/Aboss2/GW1/JL/bga2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/HCSP/sp18",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
"/Aboss2/BOX/box2",
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