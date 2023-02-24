class TestCase:
    def __init__(self, name) -> None:
        self.name = name

    def run(self) -> None:
        method = getattr(self, self.name)
        method()


class WasRun(TestCase):
    def __init__(self, name) -> None:
        self.was_set_up = None
        self.was_run = None
        TestCase.__init__(self, name)

    def test_method(self) -> None:
        self.was_run = 1


class TestCaseTest(TestCase):
    def test_running(self):
        test = WasRun("test_method")
        assert not test.was_run
        test.run()
        assert test.was_run

    def test_set_up(self):
        test = WasRun("test_method")
        test.run()
        assert test.was_set_up


TestCaseTest("test_running").run()
TestCaseTest("test_set_up").run()
