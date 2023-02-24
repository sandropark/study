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

    def test_template_method(self):
        self.test = WasRun("test_method")
        self.test.run()
        assert self.test.log == "set_up test_method tear_down"


TestCaseTest("test_template_method").run()
