
#include <ansi.h>
void init()
{
        object me, hero, ob, room;
        object azhu;

        me = this_player();
        room = environment(me);
        hero = present("qiao feng", room);
        azhu = present("a zhu", room);
        if( objectp(hero) && objectp(azhu) && me->query_temp("juxianzhuang_step") == 13 )
        {

                if( room->query("short") == "�θ�����" )
                {
                        tell_object(me, HIW "�Ƿ������������˵������һ�����Ҫ������Ӣ�ۺȾƶ��塣���ǳ�Ȼ�����Ӣ�ۣ�����ׯ����Ӧ�ò���Ϊ����ġ�\n"
                                            "�����Ǿ��յ����꣬����ǧ���չ˰��������ȫ��\n"
                                            "�԰�������ƣ����Լ��̫�ã�ֻ��Ѧ��ҽ�žȵ��������мǣ��мǡ�\n" NOR);
                        message_vision(HIW "$N����һ�������˵�����������ڼ�Ӣ�ۣ����������Ƿ�ɽ������ռ��м���֮�⣬���Ǹɱ�������\n"
                                           "��һλ����Ҫɱ��ĳ�ģ���������һ�룬�Ӵ˶������ս���һ�ʹ�������ɱ�㲻����������ɱ�Ҳ��㸺�塣\n"
                                           "����Ӣ�ۣ���Ϊ֤����\n" NOR,
                                           hero, me);
                        message_vision(HIW "����ƺȰգ�$NԾ��Ժ�ӣ������ȵ�������һ��������һ��ս��������ʱȺ�۷�ӵ���ϡ�\n" NOR, hero, me);
                        azhu->set_leader(me);
                        hero->command("go east");
                        room = environment(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/sengren");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/sengren");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/sengren");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/youji");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/youju");
                        ob->move(room);
                        ob->kill_ob(hero);
                }
                else
                if( room->query("short") == "���䳡" )
                {
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/sengren");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/sengren");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/xu");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/shanzheng");
                        ob->move(room);
                        ob->kill_ob(hero);
                }
                else
                if( room->query("short") == "�θ���Ժ" )
                {
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/sengren");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/sengren");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/xuan-nan");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/xuan-ji");
                        ob->move(room);
                        ob->kill_ob(hero);
                }
                else
                {
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/sengren");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/sengren");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/haojie");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/gaibang");
                        ob->move(room);
                        ob->kill_ob(hero);
                        ob = new("/maze/juxianzhuang/npc/sengren");
                        ob->move(room);
                        ob->kill_ob(hero);
                }
        }
}
