// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIY"ɽ������"NOR,({"boxs5a4"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"����ϵͳ������"+this_object()->query("name")+",\nʹ��(openbox boxs5a4)"ZJURL("cmds:openbox boxs5a4")ZJSIZE(15)"��"NOR"����!\n");
	    set("unit","��");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxs5a4",1);
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
"/HELL5/GuaiWu4/JL/bg1",
"/HELL5/GuaiWu4/JL/bg2",
"/HCSP/sp18",
"/HELL5/GuaiWu4/JL/bg3",
"/HELL5/GuaiWu4/JL/bg4",
"/HELL5/GuaiWu4/JL/bg5",
"/HELL5/GuaiWu4/JL/bg6",
"/HELL5/GuaiWu4/JL/bg7",
"/HELL5/GuaiWu4/JL/bg8",
"/HELL5/GuaiWu4/JL/bg9",
"/HELL5/GuaiWu4/JL/bg10",
"/HELL5/GuaiWu4/JL/bg11",
"/HELL5/GuaiWu4/JL/bg12",
"/HELL5/GuaiWu4/JL/xwk1",
"/HELL5/GuaiWu4/JL/xwk2",
"/HELL5/GuaiWu4/JL/xwk3",
"/HELL5/GuaiWu4/JL/xwk4",
"/HELL5/GuaiWu4/JL/xwk5",
"/HELL5/GuaiWu4/JL/dqk1",
"/HELL5/GuaiWu4/JL/dqk2",
"/HELL5/GuaiWu4/JL/dqk3",
"/HELL5/GuaiWu4/JL/dqk4",
"/HELL5/GuaiWu4/JL/dqk5",
"/HELL5/GuaiWu4/JL/xwk1",
"/HELL5/GuaiWu4/JL/xwk2",
"/HELL5/GuaiWu4/JL/xwk3",
"/HELL5/GuaiWu4/JL/xwk4",
"/HELL5/GuaiWu4/JL/xwk5",
"/HELL5/GuaiWu4/JL/dqk1",
"/HELL5/GuaiWu4/JL/dqk2",
"/HELL5/GuaiWu4/JL/dqk3",
"/HELL5/GuaiWu4/JL/dqk4",
"/HELL5/GuaiWu4/JL/dqk5",
"/HELL5/GuaiWu4/JL/xwk1",
"/HELL5/GuaiWu4/JL/xwk2",
"/HELL5/GuaiWu4/JL/xwk3",
"/HELL5/GuaiWu4/JL/xwk4",
"/HELL5/GuaiWu4/JL/xwk5",
"/HELL5/GuaiWu4/JL/dqk1",
"/HELL5/GuaiWu4/JL/dqk2",
"/HELL5/GuaiWu4/JL/dqk3",
"/HELL5/GuaiWu4/JL/dqk4",
"/HELL5/GuaiWu4/JL/dqk5",
});

	object me = this_player();
	if (me->is_busy())
	      { write("����һ������δ��ɣ�\n"); return 1;}
	if( me->is_fighting() )
	      { write("ս���п����䣿����ѽ��\n"); return 1;}

	message_vision(HIY"$N�������["+this_object()->query("name")+"]�ĸ���,���仯Ϊһ���ɫ�⻪��"NOR"\n",me);
	i=random((int)sizeof(box));

	ob = new(box[i]);

    if(ob->query("base_value"))
    {
       num=random(1)+1;
       ob->set_amount(1);
    }

  tell_object(me,""HIY"*****************************************************\n");
  tell_object(me,""HIY"��ϲ: "NOR"���["+this_object()->query("name")+"]�еõ���..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIY"*****************************************************"NOR"\n");
    ob->move(me);
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}