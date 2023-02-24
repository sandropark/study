class TestResult:
    def __init__(self):
        self.run_count = 1

    def summary(self) -> str:
        return f'{self.run_count} run, 0 failed'


class TestCase:
    def __init__(self, name):
        self.name = name

    def run(self) -> TestResult:
        self.set_up()
        method = getattr(self, self.name)
        method()
        self.tear_down()
        return TestResult()

    def set_up(self): pass
    def tear_down(self): pass


class WasRun(TestCase):
    def __init__(self, name):
        self.log = None
        TestCase.__init__(self, name)

    def set_up(self):
        self.log = "set_up "

    def test_method(self):
        self.log += "test_method "

    def tear_down(self):
        self.log += "tear_down"


class TestCaseTest(TestCase):

    def test_template_method(self):
        self.test = WasRun("test_method")
        self.test.run()
        assert self.test.log == "set_up test_method tear_down"

    def test_result(self):
        test = WasRun("test_method")
        result = test.run()
        assert result.summary() == "1 run, 0 failed"


TestCaseTest("test_template_method").run()
TestCaseTest("test_result").run()
