//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
  set ("short", "������");
  set ("long", @LONG

���Ǳ����⣬һ������ӡ�����ŵ��������룬��������Ĺܼ���
�����渺��ģ�һЩ�����ڸ��ܱ����Ĺܼ�˵��ʲô��
LONG);

  set("exits", ([
        "west"    : __DIR__"eastway2",
      ]));
  set("objects", ([
      CLASS_D("shushan/lingyunzi") : 1,
       __DIR__"npc/guanjia" : 1,


      ]));
  setup();
}

