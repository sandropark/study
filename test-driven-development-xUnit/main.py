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

    def run(self, result) -> TestResult:
        result.test_started()

        self.set_up()
        try:
            method = getattr(self, self.name)
            method()
        except:
            result.test_failed()
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


class TestSuite:
    def __init__(self):
        self.tests = []

    def add(self, test):
        self.tests.append(test)

    def run(self, result):
        for test in self.tests:
            test.run(result)


class TestCaseTest(TestCase):

    def set_up(self):
        self.result = TestResult()

    def test_template_method(self):
        test = WasRun("test_method")
        test.run(self.result)
        assert test.log == "set_up test_method tear_down"

    def test_result(self):
        test = WasRun("test_method")
        test.run(self.result)
        assert self.result.summary() == "1 run, 0 failed"

    def test_failed_result_formatting(self):
        self.result.test_started()
        self.result.test_failed()
        assert self.result.summary() == "1 run, 1 failed"

    def test_failed_result(self):
        test = WasRun("test_broken_method")
        test.run(self.result)
        assert self.result.summary() == "1 run, 1 failed"

    def test_suite(self):
        suite = TestSuite()
        suite.add(WasRun("test_method"))
        suite.add(WasRun("test_broken_method"))
        suite.run(self.result)
        assert self.result.summary() == "2 run, 1 failed"


result = TestResult()

TestCaseTest("test_template_method").run(result)
TestCaseTest("test_result").run(result)
TestCaseTest("test_failed_result_formatting").run(result)
TestCaseTest("test_failed_result").run(result)
TestCaseTest("test_suite").run(result)

print(result.summary())
