// unarmed.c
inherit SKILL;
void skill_improved(object me)
{
	if (me->query_skill("spells",1)%10==0) {
		tell_object(me, HIW "�����ĵ����õ�����ߣ����"+HIY"��������ǡ�"+NOR+"����ˡ�"NOR"\n");
	}
}
