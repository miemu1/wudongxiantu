int main(object me, string arg)
{
	string str;
	
	if (!environment(me)->query("is_fuben"))
	{
		tell_object(me,"��ָ��ֻ���ڸ�����ʹ�á�\n");
		return 1;
	}
	
	if (!arg)
	{
		str = "��Ҫִ��ʲô����\n" + ZJOBACTS2 + ZJMENUF(2,2,9,30);
		str += "ʹ��׷ɱ��:use zhuisha ling" + ZJSEP;
		str += "�ص�Ӫ��:jiaofei go_yingdi";
		tell_object(me, ZJOBLONG + str + "\n");
		return 1;
	}
	
	if (arg == "go_yingdi")
	{
		me->move((me->query_temp("fb_mem"))->query("yingdi"));
		tell_object(me, "��������Ӫ�ء�\n");
		return 1;
	}
	
	return 1;
}