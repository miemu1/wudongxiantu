// chuji_box.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIM"���챦��"NOR,({"boxs1"}));
	set_weight(5000);

	if( clonep() )
		set_default_object(__FILE__);
	else
       {
	    set("long",
		"����ϵͳ������"+this_object()->query("name")+",\nʹ��(openbox boxs1)"ZJURL("cmds:openbox boxs1")ZJSIZE(15)"��"NOR"����!\n");
	    set("unit","��");
	    set("win_box",1);
	}
}
void init()
{
    if (environment()==this_player())
    add_action("do_openbox","openbox boxs1",1);
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
"/clone/good/qitiandasheng/bg1",
"/clone/good/qitiandasheng/bg2",
"/clone/good/qitiandasheng/bg4",
"/clone/good/qitiandasheng/bg5",
"/clone/good/qitiandasheng/bg6",
"/clone/good/qitiandasheng/bg7",
"/clone/good/qitiandasheng/bg8",
"/clone/good/qitiandasheng/bg9",
"/clone/good/qitiandasheng/bg10",
"/clone/good/qitiandasheng/bg11",
"/clone/good/qitiandasheng/bg12",
"/clone/good/qitiandasheng/xwk1",
"/clone/good/qitiandasheng/xwk2",
"/clone/good/qitiandasheng/xwk3",
"/clone/good/qitiandasheng/xwk4",
"/clone/good/qitiandasheng/xwk5",
"/clone/good/qitiandasheng/dqk1",
"/clone/good/qitiandasheng/dqk2",
"/clone/good/qitiandasheng/dqk3",
"/clone/good/qitiandasheng/dqk4",
"/clone/good/qitiandasheng/dqk5",
});

	object me = this_player();
	if (me->is_busy())
	      { write("��Ķ���δ��ɣ�\n"); return 1;}
	if( me->is_fighting() )
	      { write("ս���д򿪱��䣿\n"); return 1;}

	message_vision(HIM"$N�������["+this_object()->query("name")+"]�ĸ���,���仯Ϊһ���ɫ�⻪��"NOR"\n",me);
	i=random((int)sizeof(box));

	ob = new(box[i]);

    if(ob->query("base_value"))
    {
       num=random(5)+1;
       ob->set_amount(1);
    }

  tell_object(me,""HIM"*****************************************************\n");
  tell_object(me,""HIR"��ϲ: "NOR"���["+this_object()->query("name")+"]�еõ���..."+chinese_number(num)+ob->query("unit")+HIM+"<< "+ob->query("name")+HIM+" >>"+NOR+"\n");
 tell_object(me,""HIM"*****************************************************"NOR"\n");
    ob->move(me);
    destruct(this_object());
	return 1;
}
int query_autoload()
{
	return 1;
}