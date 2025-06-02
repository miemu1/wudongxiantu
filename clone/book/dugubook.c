// jiuyang.c
#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;
 
void create()
{
        set_name("�����¾Ž��б���", ({ "dugu canben", "canben", "dugu" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ�������Ĳ����ҳ��Ķ��¾Ž��б���ֻ���ڲ�\n"
                        "�ڿ���֮�У���ҳ����Щ�����ȱ��\n",
                        );
                set("value", 1);
                set("no_sell", 1);
                set("material", "paper");
        }
}

void init()
{
        add_action("do_read", "read");
}

int do_read(string arg)
{
        object me = this_player();
        
        if (! arg || ! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
                
        if (me->query("dugu-jiujian/nothing"))
                return notify_fail("�Ȿ�б�������˵û���κ��ô��ˡ�\n");
                
        if (me->query_skill("dugu-jiujian", 1) < 300)
                return notify_fail("��Ķ��¾Ž���Ϊ̫ǳ���޷��������а��ء�\n");
                
        tell_object(me, "����ϸ���ж��б�����Ľ���......\n"
                        "�㿪ʼ�����񣬳�������........\n"
                        "ʱ��ܿ�Ĺ�ȥ..................\n"
                        "ͻȻһ�գ���ë���ٿ���������Ц������\n"
                        "�㷢����ԭ�����жԽ�������ʶ����ô��Ц�����ơ�\n"
                        "��ͨ���˶��¾Ž��ľ��衸" HIR "����" NOR "���İ��ء�\n");
        tell_object(me, "ͻȻ���¾Ž��б������һƬƬ��Ƭ����ʧ�ˡ�\n");
        me->set("dugu-jiujian/nothing", 1);
        me->improve_skill("martial-cognize", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        me->improve_skill("martial-cognize", 1500000); 
        
        destruct(this_object());
        return 1;
}



