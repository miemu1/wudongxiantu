//����ɽ�ɡ�mhxy-yushu 2001/2
//modified by hanchat@txwx2005
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","ɽ´");
  set ("long", @LONG

���۵�С·��ͷ��Ȼ����,���Ϸ��������������ü���ˡ����ںܾ�û
���߶���·�ߵ�С��(grass)��������ô����,��֪����������û��ʲô
������
LONG);

//  set("outdoors", 2);
  	
  set("exits", ([      
// "southeast" : __DIR__"womeifeng",
 "northeast" : __DIR__"road0",
 "southwest" : __DIR__"shanlu1",

 ]));


     set("item_desc", ([
         "grass" : HIR"\t\t\��ݿ���������������Ĳ�̫һ��, Ҫ��Ҫ�ھ�(wacao)������\n"NOR
      ]));

 setup();
}

void init()
{
  add_action("do_wajue", "wacao");
}
int do_wajue(string arg)
{
object yaocai,weapon, me=this_player();
if ((arg != "��" && arg != "grass") || !arg)
	return notify_fail("��Ҫ��ʲô��\n");

if(!query("havewajue"))
	return notify_fail("������̫���ˣ�����Ѿ��������ˡ�\n");

weapon=me->query_temp("weapon");
if (!weapon)
    return notify_fail("�㲻����Ҫ�����ڰɣ�\n");

if (weapon->query("skill_type")=="dagger")
{
	message_vision("$N�����е�"+weapon->name()+"��ʼ�ھ���ϵĲݡ�\n",me);
	message_vision("$N�ھ�һ��ϡ�е�ҩ�ġ�\n",me); 
	yaocai=new("/d/shushan/obj/yaocai");
	yaocai->move(me);
	set("havewajue", 0);
	return 1;
}

	message_vision("$N�����е�"+weapon->name()+"��ʼ�ھ���ϵĲݡ�\n",me);
	message_vision("$Nʹ�õĹ��߲���,�����ڲ�������\n",me); 
return 1;
}

void reset()
{
	::reset();
	set("havewajue", 1);
}
