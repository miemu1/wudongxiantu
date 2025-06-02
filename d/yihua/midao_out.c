#include <ansi.h>
inherit ROOM;
 
int do_pick(string arg) ;

void create()
{
        set("short", "�ܶ�");
        set("long",@LONG
��������һ���ܶ��С�������ߺܰ���ֻ������ԼԼ����������Щ�仨��ݡ�
����֮�е�һ��ʯͷ�Ϻ������һ����ϻ(xia)�� ��ͻȻ�ŵ�һ���������ζ����
�治֪������ʲô�ط��ˡ�
LONG);   
        set("item_desc", ([
        "xia" : "����ϸ����һ��ʯϻ�����������ƺ����������飬�ƺ����������ó���(pick book)��",
	"bi": "ʯ���Ϻ���̻���ʲô������ͼ�����㶢��ͼ����������(lingwu)��������",
    ]) );
        set("exits", ([
				"out"  : __DIR__"midao",
				"west"   : __DIR__"xiaojing2",
]));
        set("objects", ([
        __DIR__"npc/huawuque" : 1,
    ]) );    

        setup();
}
void init()
{
	        add_action("do_think", "lingwu");
            add_action("do_pick","pick");
}
void reset()
{
        ::reset();
        set("get_available" , 2);
}

int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="book" )
              return notify_fail("��Ҫȡʲô?\n");
obj=present("hua wuque",environment(me));
if(obj && living(obj))
        
       {
        message_vision(YEL"����ȱ˵����û�й�����ͬ����ô�����أ�"
                       "���������ˣ�\n" NOR,me);
        return 1 ;
       }
       if ( query("get_available") )  {
       obj = new (__DIR__"obj/yihuapu");
       obj->move(me);
       obj = new (__DIR__"obj/yifengjianpu");
       obj->move(me);
       add("get_available", -2);
       message_vision("$N�ӱ�ϻ��ȡ�������顣\n",me );
       }
       else
       return notify_fail("�ؼ��Ѿ������˽����ȵ��ˡ�\n");
       return 1;
}


int do_think(string arg)
{
        object here, me = this_player();
        int add;
      int level;

       if (me->query("gender") != "Ů��")
                return notify_fail("�㴿��֮�����㣬��������������񹦡�\n");

        if (! living(me) || arg != "bi")
                return notify_fail("��Ҫ����ʲô��\n");

      if (me->query("sex/times"))
                return notify_fail("�������񹦱����Ǵ���֮��\n");


        if (me->is_busy() || me->is_fighting())
                return notify_fail("��������æ���ء�\n");

        if ((int)me->query("int") < 25)
                return notify_fail("����������Ȼ�������е㲻���ס�\n");

        level = me->query_skill("mingyu-gong", 1);

   	if ((int)me->query_skill("mingyu-shengong", 1) < 100) 
                return notify_fail("�Ƿ��Ȱ�ڤ��������������\n");

        if (me->query_skill("force", 1) < level)
                return notify_fail("��Ի����ڹ�����⻹�������޷���������"
                                   "��������񹦡�\n");

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("��Ի���ȭ�ŵ���⻹�������޷���������"
                                   "��������񹦡�\n");

        if ((int)me->query_skill("force", 1) < 200)
                return notify_fail("��Ļ����ڹ���򲻹����޷�����ʯ��"
                                   "�ϵ��书��\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬�޷�ѧϰʯ���ϵ��书��\n");

        if ((int)me->query("jing") < 85)
                return notify_fail("�����ھ��񲻼ã�����ƣ�룬������Ϣ"
                                   "һ��ɡ�\n");

        if ((int)me->query_skill("martial-cognize", 1) < 100)
                return notify_fail("��������񹦹�����£����Լ�����ѧ����"
                                   "ȫȻ�޷����ס�\n");


        if ((int)me->query_skill("mingyu-gong", 1) >= 200)
                return notify_fail("�����ʯ���ϼ��ص��书������˵̫ǳ�ˣ������"
                                   "ʲôҲûѧ����\n");

        me->receive_damage("jing", 75);

        if (me->can_improve_skill("mingyu-gong"))
                me->improve_skill("mingyu-gong", add);

        me->start_busy(random(2));
        message_vision(HIY "\n$N" HIY "�۾�����Ĳ���ǽ�������ص��񹦣�"
                       "��������\n" NOR, me);
        write(HIC "��ԡ����񹦡������µ�����\n" NOR);
        return 1;
}