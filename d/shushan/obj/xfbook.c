//book by yushu 2001.2
inherit ITEM;
int do_read(string arg);
void create()
{
        set_name("����ɽ������", ({"shushan spells","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	  set("long",
	"����д�������������,�������ǹ�����ɽ�ɷ�������������\n");
        set("material", "paper");
        set("value", 1000);
        set("skill", ([
                        "name": "xianfeng-spells",
                        "exp_required": 100000,
                        "jing_cost": 300,
                        "difficulty": 300,
                        "max_skill": 100,
]) );
          }
}
void init()
{
    add_action("do_read", "read");
}
int do_read(string arg)
{
    object me=this_player();
    if(me->query("family/family_name")!="��ɽ��")
        return notify_fail("������ɽ�Ĳ��ܶ��Ȿ�飡\n");
}
