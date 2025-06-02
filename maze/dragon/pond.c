inherit ROOM; 
#include <ansi.h> 
void create()
{
   set("short", "����");
   set("long",
"[1;32m���Ǵ������������һ��СС�ĳ�����һ��С���ź���ڳ�\n"
"���ϡ���ˮ���̣������м���ʢ����˯�����ۺ죬��ף���ƣ������ű�\n"
"�̵�Ҷ�ӣ�Ư����С�����ϣ�ɷ������ϲ����һ�ô�����������ߣ���˿\n"
"���Ʈ�衣����̫��ʯ(stone)ɢ��ط��ڳ����ߡ�\n"
);
   set("exits", ([ /* sizeof() == 4 */
      "southeast" : __DIR__"lake1",
   ]));
   
   set("item_desc", ([
      "̫��ʯ": "���������̫��ʯ��ɢ��ط��ڳ����ߣ�ʯͷ��һ���ֱ����������¡�\n",
      "stone": "���������̫��ʯ��ɢ��ط��ڳ����ߣ�ʯͷ��һ���ֱ����������£���������ò��Ӧ���ܹ���(push)�ö���\n",
      "����": "�����ڲ�Զ���ĳ����ߣ������������ڳ����ϡ�\n",
      "tree": "�����ڲ�Զ���ĳ����ߣ������������ڳ����ϡ�\n",
      "˯��": "�뿪��˯����˯��֮�е����ˣ�Ư���ڱ��̵ĳ����ϡ�\n",
      "flower": "�뿪��˯����˯��֮�е����ˣ�Ư���ڱ��̵ĳ����ϡ�\n",
   ]) );
      set("no_magic", 1);
	setup();
}

void init()
{
   add_action("do_push", "push");
}

int do_push(string arg)
{
   object me, qiuyin, where;
  
   me = this_player();
        where=environment(me); 
   if(where->query_temp("marks/moved")) return notify_fail("ʯͷ�ƺ������ƹ����Ѿ��ɶ��ˡ�\n");
   if (!arg || arg != "stone" && arg != "ʯͷ") 
      return notify_fail("��Ҫ��ʲô ? \n");
   message("vision",me->name()+"����������̫��ʯ��ʯ�ߵ����ɶ��ˣ�¶����һ�����ֵ���򾡣\n", me);
   qiuyin = new("/quest/tulong/obj/qiuyin");
   qiuyin->move(where);
   where->set_temp("marks/moved", 1); 
   return 1;

}

