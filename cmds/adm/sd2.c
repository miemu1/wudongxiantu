// study.c

#include <skill.h>
#include <command.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object book, env = environment(me);

	if (! arg)
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

	if (me->is_fighting())
		return notify_fail("���޷���ս����ר�������ж���֪��\n");

	if (environment(me)->query("no_learn") || environment(me)->query("no_study"))
		return notify_fail("���޷�������ط����Ķ��顣\n");

	if (! objectp(book = present(arg, me)))
		return notify_fail("û�Ȿ��ɶ�����\n");

	if (! mapp(book->query("skill")))
		return notify_fail("���޷�����������ѧ���κζ�����\n");

	if (!me->query_skill("literate", 1))
		return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	message("vision", me->name() + "��ʼר�ĵ��ж�" + book->name() + "��\n", environment(me), me);

	me->set("book_skill/"+book->query("skill/name"),1);
	me->delete("afk");
	me->set("afk/room", env);
	me->set("afk/book", book);
	me->set("afk/file", "dushu");
	return 1;
}

int help(object me)
{
	write( @HELP
ָ���ʽ: study|du <��Ʒ����>

���ָ��ʹ�����ͨ���Ķ����Ż�������Ʒ��ѧĳЩ����, ��ǰ��
��: �㲻���Ǹ�����ä����

see also : learn
HELP );
	return 1;
}
