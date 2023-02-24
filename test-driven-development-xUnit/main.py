class TestCase:
    def __init__(self, name) -> None:
        self.name = name

    def run(self) -> None:
        method = getattr(self, self.name)
        method()


class WasRun(TestCase):
    def __init__(self, name) -> None:
        self.was_run = None
        TestCase.__init__(self, name)

    def test_method(self) -> None:
        self.was_run = 1


test = WasRun("test_method")
print(test.was_run)
test.run()
print(test.was_run)
