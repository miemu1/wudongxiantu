// Room: lianhuachi ������
inherit ROOM;
string look_CAI();
void create()
{
    set("short", "������");
    set("long", @LONG
�������ƻ����ڵ�һ�������أ����ڿ�������������
��ס������ȥժһ�䡣����������ڴ����������������ˣ�
LONG
    );
    set("exits", ([
           "east" : __DIR__"xiaojing2",
    ]));
    /*set("item_desc",([
        "CAI"       :   (: look_CAI :),
    ]));*/
    set("no_steal", "1");
    set("no_array", "1");
    setup();
}
void init()
{
	  add_action("do_CAI","CAI");
        add_action("no_action", "lian");
        add_action("no_action", "practice");
}
int no_action(string str)
{
     write(HIY"����ɲ�������Ŷ.. \n"NOR);
        return 1;
}
/*
int do_CAI(string arg)
{
    object me, killer;
    int i, ging_cost, qi_cost;
    me = this_player();
        i = (int)me->query_skill("dodge", 0) + random(200);
    ging_cost = 1000 / (int)me->query_int();
     qi_cost = 1000 / (int)me->query_int();
    if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
        i = 0;
        tell_object(me,"���������Ϻ�Ҷ������ȥ����һ��������\n");
      me->move("/d/yihua/xiaojing2");
		me->start_busy(1);
    reset_eval_cost();
    if ( i < 50)
    {
        killer = new(("/d/yihua/npc") + "/lianxing");
         me->set_temp("last_damage_from",killer);
                me->die();
        destruct(killer);
    }
    else{ if( i < 125)
        me->unconcious();
    else {
                if (me->query_skill("dodge", 1)<450)
                         me->improve_skill("dodge", 3000 + (int)me->query_skill("dodge", 1));
     else me->improve_skill("dodge", 1500 + (int)me->query_skill("dodge", 1)/6);
        me->receive_damage("jing", ging_cost );
        me->receive_damage("qi", qi_cost );
        me->set_temp("die_for","������");
        me->delete_temp("last_damage_from");
    }
   }
    return 1;
}
*/
string look_chi()
{
    return  "�����������صĳرߣ�������ȥ��һƬ�����أ����̲�ס��ȥ���вɶ�����.\n";
}
