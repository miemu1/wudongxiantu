// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"���䱦��"NOR,({"shengs4"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"����ϵͳ������"+this_object()->query("name")+",\nʹ��(openbox shengs4)"ZJURL("cmds:openbox shengs4")ZJSIZE(15)"��"NOR"����!\n");
	    set("unit","��");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox shengs4",1);
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
"/HELL8/GuaiWu4/JL/bg1",
"/HELL8/GuaiWu4/JL/bg2",
"/HELL8/GuaiWu4/JL/bg3",
"/HELL8/GuaiWu4/JL/bg4",
"/HELL8/GuaiWu4/JL/bg5",
"/HELL8/GuaiWu4/JL/bg6",
"/HELL8/GuaiWu4/JL/bg7",
"/HELL8/GuaiWu4/JL/bg8",
"/HELL8/GuaiWu4/JL/bg9",
"/HELL8/GuaiWu4/JL/bg10",
"/HELL8/GuaiWu4/JL/bg11",
"/HELL8/GuaiWu4/JL/bg12",
"/HELL8/GuaiWu4/JL/xwk1",
"/HELL8/GuaiWu4/JL/xwk2",
"/HELL8/GuaiWu4/JL/xwk3",
"/HELL8/GuaiWu4/JL/xwk4",
"/HELL8/GuaiWu4/JL/xwk5",
"/HELL8/GuaiWu4/JL/dqk1",
"/HELL8/GuaiWu4/JL/dqk2",
"/HELL8/GuaiWu4/JL/dqk3",
"/HELL8/GuaiWu4/JL/dqk4",
"/HELL8/GuaiWu4/JL/dqk5",
"/HELL8/GuaiWu4/JL/xwk1",
"/HELL8/GuaiWu4/JL/xwk2",
"/HELL8/GuaiWu4/JL/xwk3",
"/HELL8/GuaiWu4/JL/xwk4",
"/HELL8/GuaiWu4/JL/xwk5",
"/HELL8/GuaiWu4/JL/dqk1",
"/HELL8/GuaiWu4/JL/dqk2",
"/HELL8/GuaiWu4/JL/dqk3",
"/HELL8/GuaiWu4/JL/dqk4",
"/HELL8/GuaiWu4/JL/dqk5",
"/HELL8/GuaiWu4/JL/xwk1",
"/HELL8/GuaiWu4/JL/xwk2",
"/HELL8/GuaiWu4/JL/xwk3",
"/HELL8/GuaiWu4/JL/xwk4",
"/HELL8/GuaiWu4/JL/xwk5",
"/HELL8/GuaiWu4/JL/dqk1",
"/HELL8/GuaiWu4/JL/dqk2",
"/HELL8/GuaiWu4/JL/dqk3",
"/HELL8/GuaiWu4/JL/dqk4",
"/HELL8/GuaiWu4/JL/dqk5",
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