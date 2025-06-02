#include <ansi.h>

string name() { return HIW "[»ðÄ§·¨]"ZJBR"»ðÑæ·ÉÁú" NOR; }
string query_name() { return "[»ðÄ§·¨]"ZJBR"»ðÑæ·ÉÁú"; }
inherit F_SSERVER;

int perform(object me, object target)
{
        int spells;
        object ob;
        object weapon;

	if((int)me->query("neili")< 5000)
	return notify_fail("ÄãµÄÄÚÁ¦Ì«²îÁË£¡\n");

	if((int)me->query_skill("bingzhi-shengdian",1)< 400)
	return notify_fail("ÄãµÄ»ðÖ®Ê¥µäÌ«²îÁË£¡\n");
    spells = me->query_skill("spells");
    if(spells < 200 )
    return notify_fail("ÄãµÄ»ù´¡ÏÉÊõ²»¹»¸ß£¡\n");
        if (find_living(me->query("id") + "huoyanfeilong"))
                return notify_fail("ÄãµÄ»ðÑæ·ÉÁú»¹Ã»ÓÐÏûÊ§£¬ÔÝÊ±ÎÞ·¨ÕÙ»½¡£\n");

        spells = me->query_spells("bingzhi-shengdian", 1);
        me->add("neili", -1000);

        // ÉèÖÃµ¶»ê
        ob = new("/kungfu/class/misc/huoyanfeilong");
        ob->init_npc(me);
        ob->move(environment(me));
        ob = new("/kungfu/class/misc/huoyanfeilong");
        ob->init_npc(me);
        ob->move(environment(me));
        me->start_busy(3);

        return 1;
}
