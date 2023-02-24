class TestResult:
    def __init__(self):
        self.run_count = 0
        self.failure_count = 0

    def test_started(self):
        self.run_count += 1

    def test_failed(self):
        self.failure_count += 1

    def summary(self) -> str:
        return f'{self.run_count} run, {self.failure_count} failed'


class TestCase:
    def __init__(self, name):
        self.name = name

    def run(self) -> TestResult:
        result = TestResult()
        result.test_started()

        self.set_up()
        method = getattr(self, self.name)
        method()
        self.tear_down()
        return result

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

    def test_broken_method(self):
        raise Exception

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

    def test_failed_result_formatting(self):
        result = TestResult()
        result.test_started()
        result.test_failed()
        assert result.summary() == "1 run, 1 failed"

    def test_failed_result(self):
        test = WasRun("test_broken_method")
        result = test.run()
        assert result.summary() == "1 run, 1 failed"


TestCaseTest("test_template_method").run()
TestCaseTest("test_result").run()
TestCaseTest("test_failed_result_formatting").run()
TestCaseTest("test_failed_result").run()
