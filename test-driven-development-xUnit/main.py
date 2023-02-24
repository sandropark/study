class TestCase:
    def __init__(self, name):
        self.name = name

    def run(self):
        self.set_up()
        method = getattr(self, self.name)
        method()

    def set_up(self):
        pass


class WasRun(TestCase):
    def __init__(self, name):
        self.log = None
        TestCase.__init__(self, name)

    def set_up(self):
        self.log = "set_up "

    def test_method(self):
        self.log += "test_method "


class TestCaseTest(TestCase):
    def set_up(self):
        self.test = WasRun("test_method")

    def test_running(self):
        self.test.run()
        assert self.test.log == "set_up test_method "

    def test_set_up(self):
        self.test.run()
        assert self.test.log == "set_up test_method "


TestCaseTest("test_running").run()
TestCaseTest("test_set_up").run()
